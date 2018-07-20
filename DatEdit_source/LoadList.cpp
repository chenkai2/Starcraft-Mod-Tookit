//---------------------------------------------------------------------------
#pragma hdrstop

#include "LoadList.h"
#include "TBLParser.h"
#include "Data.h"
#include "EntryData.h"
#include "Options.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
//---------------------------------------------------------------------------
/*
############################################################################
This routine loads the content of a given text file into a target
dropdown list, adding the numbering to the list if specified to.
############################################################################
*/

void LoadList (TComboBox* Target,String List,bool IncludeID) {
     Target->Items->Clear();
     if (FileExists(Form1->GetProgPath()+"Data\\"+List+".txt")) {
        Target->Items->LoadFromFile(Form1->GetProgPath()+"Data\\"+List+".txt");
        if (IncludeID == true) {
           for (int i=0;i<Target->Items->Count;i++) {
               Target->Items->Strings[i] = String(i)+"-"+Target->Items->Strings[i];
           }
        }
     }
     else {
        MessageDlg(("The following list was not found: "+List+".txt\n DatEdit will continue to operate, but it will probably explode at some point.").c_str(), mtError, TMsgDlgButtons() << mbOK, 0);
     }
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine loads the content of a TBL file to a designated dropdown list.
############################################################################
*/

void LoadTBLList (TComboBox* Target,String TBLType) {
Target->Items->Clear();
for (int i=0;i<5;i++) {
    if (TBLType == GetTBLType(i)) {
       if (Form1->GetTBLIsMPQImport(i) == false) {
          ReadTBL(&Form1->TBLs[i], Target->Items);
       }
       else {
          ReadTBL(&Form1->MpqTBLs[i], Target->Items);
       }
       break;
    }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This function looks up and returns the list index of an entry when
given its ID. It is used with the non-by-ID sorting methods, when the
entry's ID (stored as the StateIndex property) is not equal to the
entry's index in the list;
############################################################################
*/

int LookEntry (int TargetID,int TargetPage) {
     String TargetEntryName;
     int ReturnID=NULL;
     for (int i=0;i<Form1->GetDATEntryList(TargetPage)->Items->Count;i++) {
         if (Form1->GetDATEntryList(TargetPage)->Items->Item[i]->StateIndex == TargetID) {
            ReturnID = i;
            break;
         }
     }
     return ReturnID;
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine loads a given DAT entry list (DATType) to a given TTreeView
type control (TargetList).It handles all 3 methods of entry sorting as
well as -if the appropriate option is set- loading custom labels for
Units,Weapons,Upgrades and Techs Editors.

NOTE:A specific entry's ID (used for proper data access etc) is stored
in the "StateIndex" property of the TTreeNode object representing the
entry in the listing.
############################################################################
*/
void LoadEntryList (TTreeView* TargetList, int DATType) {
     TargetList->ClearSelection();
     TargetList->Items->Clear();
     TargetList->Show();
     TStringList *List = new TStringList();
     TTreeNode *Parent = NULL;
     String Name="";

     //Load a list of entry names from the default listings or from the "stat_txt.tbl" file
     if (Form1->Options.UseCustomLabels == false || (DATType != 0 && DATType != 1 && DATType != 5 && DATType != 6)) {
        List->AddStrings(Form1->GetDATEntryNames(DATType));
     }
     else if (Form1->Options.UseCustomLabels == true) {
        if (Form1->GetTBLIsMPQImport(0) == false) {
           ReadTBL(&Form1->TBLs[0], (TStrings*)List);
        }
        else {
           ReadTBL(&Form1->MpqTBLs[0], (TStrings*)List);
        }
     }
     TargetList->Items->BeginUpdate();

     //The "ID Sort" method.It simply load the entry's name from the list
     if (Form1->GetSortingStyle(DATType) == 2) {
        TargetList->ShowRoot = false;
        TargetList->ShowLines = false;
        TargetList->ShowButtons = false;
        for (int i=0;i<Form1->GetDATFile(DATType)->GetOutputEntrycount();i++) {
            if (List->Strings[i].Pos("None") != 0 && Form1->Options.UseCustomLabels == false) {
	       continue;
            }
            else {
               if (i >= Form1->GetDATFile(DATType)->GetInputEntrycount()) {
                  Name = "["+String(i)+"] "+"Extra entry"+String(i-Form1->GetDATFile(DATType)->GetInputEntrycount());
               }
               else if (Form1->Options.UseCustomLabels == true) {
                  if (DATType != 1 && DATType != 5 && DATType != 6) {
                     Name = "["+String(i)+"] "+List->Strings[i];
                  }
                  else if (DATType == 1 || DATType == 5 || DATType == 6) {
                     Name = "["+String(i)+"] "+List->Strings[GetNameID(DATType,i)];
                  }
               }
               else {
                  Name = "["+String(i)+"] "+List->Strings[i];
               }
               TTreeNode* Dummy = TargetList->Items->AddChild(NULL, Name);

               for (int j=0;j<Form1->Bookmarks->Count-4;j++) {
                   if (Form1->Bookmarks->Items[j]->Tag == DATType) {
                      for (int k=0;k<Form1->Bookmarks->Items[j]->Count;k++) {
                          if (GetBookmarkID(Form1->Bookmarks->Items[j]->Items[k]->Caption) == i) {
                             Dummy->ImageIndex = 1;
                             Dummy->SelectedIndex = 1;
                             break;
                          }
                          else {
                             Dummy->ImageIndex = 0;
                             Dummy->SelectedIndex = 0;
                          }
                      }
                   }
                   else {
                        Dummy->ImageIndex = 0;
                        Dummy->SelectedIndex = 0;
                   }
               }
               Dummy->StateIndex = i;
            }            
        }
     }

     //Other sorting methods: "Origin sort" and "Data sort".
     //They follow almost exactly the same algorithm, the only difference
     //being in the determination of the "Parent" control to hook the entry up to.
     else if (Form1->GetSortingStyle(DATType) != 2) {
          TargetList->ShowRoot = true;
          TargetList->ShowLines = true;
          TargetList->ShowButtons = true;
          HTREEITEM MainNodes[4];
          MainNodes[0] = (TargetList->Items->AddChild(NULL, "Zerg "+GetDataType(DATType)))->ItemId;
          MainNodes[1] = (TargetList->Items->AddChild(NULL, "Terran "+GetDataType(DATType)))->ItemId;
          MainNodes[2] = (TargetList->Items->AddChild(NULL, "Protoss "+GetDataType(DATType)))->ItemId;
          MainNodes[3] = (TargetList->Items->AddChild(NULL, "Other "+GetDataType(DATType)))->ItemId;
          if (DATType == 0) {
             for (int i=0;i<4;i++) {
                 TargetList->Items->GetNode(MainNodes[i])->StateIndex = -1;
                 TargetList->Items->GetNode(MainNodes[i])->ImageIndex = 0;
                 TargetList->Items->GetNode(MainNodes[i])->SelectedIndex = 0;
                 TargetList->Items->AddChild(TargetList->Items->GetNode(MainNodes[i]), "Ground Units");
                 TargetList->Items->AddChild(TargetList->Items->GetNode(MainNodes[i]), "Air Units");
                 TargetList->Items->AddChild(TargetList->Items->GetNode(MainNodes[i]), "Heroes");
                 TargetList->Items->AddChild(TargetList->Items->GetNode(MainNodes[i]), "Buildings");
                 TargetList->Items->AddChild(TargetList->Items->GetNode(MainNodes[i]), "Addons");
                 TargetList->Items->AddChild(TargetList->Items->GetNode(MainNodes[i]), "Special Buildings");
                 TargetList->Items->AddChild(TargetList->Items->GetNode(MainNodes[i]), "Special");
                 TargetList->Items->AddChild(TargetList->Items->GetNode(MainNodes[i]), "Critters");
                 TargetList->Items->AddChild(TargetList->Items->GetNode(MainNodes[i]), "Powerups");
                 TargetList->Items->AddChild(TargetList->Items->GetNode(MainNodes[i]), "Resources");
                 TargetList->Items->AddChild(TargetList->Items->GetNode(MainNodes[i]), "Special");
                 TargetList->Items->AddChild(TargetList->Items->GetNode(MainNodes[i]), "Special Buildings");
             }
          }

          for (int i=0;i<Form1->GetDATFile(DATType)->GetOutputEntrycount();i++) {
              if (Form1->Options.UseCustomLabels == false && List->Strings[i].Pos("None") != 0) {
	         continue;
              }
              else {
                 if (i >= Form1->GetDATFile(DATType)->GetInputEntrycount()) {
                    Name = "["+String(i)+"] "+"Extra entry"+String(i-Form1->GetDATFile(DATType)->GetInputEntrycount());
                 }
                 else if (Form1->Options.UseCustomLabels == true) {
                    if (DATType != 1 && DATType != 5 && DATType != 6) {
                       Name = "["+String(i)+"] "+List->Strings[i];
                    }
                    else if (DATType == 1 || DATType == 5 || DATType == 6) {
                       Name = "["+String(i)+"] "+List->Strings[GetNameID(DATType,i)];
                    }
                 }
                 else {
                    Name = "["+String(i)+"] "+List->Strings[i];
                 }
                 if (Name.Pos("None") != 0) {
	            continue;
                 }

                 switch (Form1->GetSortingStyle(DATType)) {
                        case 0:
                             if (DATType == 0) {
                                Parent = TargetList->Items->GetNode(MainNodes[GetUnitsSortData(i)])->Item[GetUnitsSortSubData(i)];
                             }
                             else {
                                Parent = TargetList->Items->GetNode(MainNodes[GetSortData(i,DATType)]);
                             }
                             break;
                        case 1:
                             if (DATType == 0) {
                                Parent = TargetList->Items->GetNode(MainNodes[Form1->Origins->Values[GetDATType(DATType)].SubString(1+i*2,1).ToInt()])->Item[Form1->Origins->Values["unitsSub"].SubString(1+i*2,1).ToInt()];
                             }
                             else {
                                Parent = TargetList->Items->GetNode(MainNodes[Form1->Origins->Values[GetDATType(DATType)].SubString(1+i*2,1).ToInt()]);
                             }
                             break;
                 }
                 TTreeNode *Dummy = TargetList->Items->AddChild(Parent, Name);
                 for (int j=0;j<Form1->Bookmarks->Count-4;j++) {
                   if (Form1->Bookmarks->Items[j]->Tag == DATType) {
                      for (int k=0;k<Form1->Bookmarks->Items[j]->Count;k++) {
                          if (GetBookmarkID(Form1->Bookmarks->Items[j]->Items[k]->Caption) == i) {
                             Dummy->ImageIndex = 1;
                             Dummy->SelectedIndex = 1;
                             break;
                          }
                          else {
                             Dummy->ImageIndex = 0;
                             Dummy->SelectedIndex = 0;
                          }
                      }
                   }
                   else {
                        Dummy->ImageIndex = 0;
                        Dummy->SelectedIndex = 0;
                   }
                 }
                 Dummy->StateIndex = i;
              }
          }

          //IF THE "DATA SORT" METHOD IS USED, IT IS POSSIBLE THAT SOME
          //OF THE BASE NODES WILL NOT HAVE ANY ENTRIES TO THEM. THIS LOOP
          //PARSES THE BASE NODES FOR ELEMENTS WITHOUT ANY CHILD NODES AND
          //REMOVES THEM.
          //THIS CODE IS ALSO ACTIVATED FOR THE UNITS EDITOR WHEN USING THE
          //"SORT BY ORIGIN" METHOD, TO REMOVE SOME SUB-BASE NODES THAT ARE
          //NOT USED IN ALL BASE NODES (FOR EXAMPLE THERE ARE NO "ZERG CRITTERS".
          if (Form1->GetSortingStyle(DATType) == 0 || DATType == 0) {
             for (int i=0;i<4;i++) {
                 if (TargetList->Items->GetNode(MainNodes[i])->Count == 0) {
                    TargetList->Items->GetNode(MainNodes[i])->Delete();
                 }
                 if (DATType == 0) {
                    for (int j=0;j<TargetList->Items->GetNode(MainNodes[i])->Count;j++) {
                        if (TargetList->Items->GetNode(MainNodes[i])->Item[j]->Count == 0) {
                           TargetList->Items->GetNode(MainNodes[i])->Item[j]->Delete();
                           j--;
                        }
                        else {
                           TargetList->Items->GetNode(MainNodes[i])->Item[j]->StateIndex = -1;
                        }
                    }
                 }
             }
          }            
     }
     TargetList->Items->EndUpdate();
     delete List;
};
//---------------------------------------------------------------------------
/*
############################################################################
This function performs the backward-reference analysis for a given
entry (NodeID) in a given DAT file (PageIndex), i.e. it looks into other
DAT files (DataRef) to see which entries are pointing to the oriinal entry,
and outputs the result in the "UsedBy" list.
############################################################################
*/

void LoadUsedList (int PageIndex,int NodeID) {
     int NoOfEntries;
     int *DataRef;
     Form1->UsedList->Items->Clear();

//Weapons used by Units
if (PageIndex == 1) {
        DataRef = Form1->GetDATFile(0)->GetData();
        NoOfEntries = Form1->GetDATFile(0)->GetOutputEntrycount();
        for (int i=0;i<NoOfEntries;i++) {
             if (NodeID == DataRef[i*Form1->GetDATFile(0)->GetVarcount()+17] || NodeID == DataRef[i*Form1->GetDATFile(0)->GetVarcount()+19]) {
                Form1->UsedList->Items->Add("[U"+String(i)+"] "+Form1->GetDATEntryNames(0)->Strings[i]);
             }
        }
//Weapons used by Orders
        DataRef = Form1->GetDATFile(10)->GetData();
        NoOfEntries = Form1->GetDATFile(10)->GetOutputEntrycount();
        for (int i=0;i<NoOfEntries;i++) {
             if (NodeID == DataRef[i*Form1->GetDATFile(10)->GetVarcount()+13]) {
                Form1->UsedList->Items->Add("[O"+String(i)+"] "+Form1->GetDATEntryNames(10)->Strings[i]);
             }
        }
}
//Flingy used by Units
else if (PageIndex == 2) {
        DataRef = Form1->GetDATFile(0)->GetData();
        NoOfEntries = Form1->GetDATFile(0)->GetOutputEntrycount();
        for (int i=0;i<NoOfEntries;i++) {
             if (NodeID == DataRef[i*Form1->GetDATFile(0)->GetVarcount()]) {
                Form1->UsedList->Items->Add("[U"+String(i)+"] "+Form1->GetDATEntryNames(0)->Strings[i]);
             }
        }
//Flingy used by Weapons
        DataRef = Form1->GetDATFile(1)->GetData();
        NoOfEntries = Form1->GetDATFile(1)->GetOutputEntrycount();
        for (int i=0;i<NoOfEntries;i++) {
             if (NodeID != 0 && NodeID == DataRef[i*Form1->GetDATFile(1)->GetVarcount()+1]) {
                Form1->UsedList->Items->Add("[W"+String(i)+"] "+Form1->GetDATEntryNames(1)->Strings[i]);
             }
        }
}
//Sprites used by Flingy and Images used by Sprites
else if (PageIndex == 3) {
         DataRef = Form1->GetDATFile(2)->GetData();
         NoOfEntries = Form1->GetDATFile(2)->GetOutputEntrycount();
         for (int i=0;i<NoOfEntries;i++) {
             if (NodeID == DataRef[i*Form1->GetDATFile(2)->GetVarcount()]) {
                Form1->UsedList->Items->Add("[F"+String(i)+"] "+Form1->GetDATEntryNames(2)->Strings[i]);
             }
         }
}
//Images used by Sprites (main pointer)
else if (PageIndex == 4) {
         DataRef = Form1->GetDATFile(3)->GetData();
         NoOfEntries = Form1->GetDATFile(3)->GetOutputEntrycount();
         for (int i=0;i<NoOfEntries;i++) {
             if (NodeID == DataRef[i*Form1->GetDATFile(3)->GetVarcount()]) {
                Form1->UsedList->Items->Add("[S"+String(i)+"] "+Form1->GetDATEntryNames(3)->Strings[i]);
             }
         }
//Images used by Sprites (Selection Circle pointer)
         DataRef = Form1->GetDATFile(3)->GetData();
         NoOfEntries = Form1->GetDATFile(3)->GetOutputEntrycount();
         for (int i=130;i<NoOfEntries;i++) {
             if (NodeID-561 == DataRef[i*Form1->GetDATFile(3)->GetVarcount()+4]) {
                Form1->UsedList->Items->Add("[S"+String(i)+"] "+Form1->GetDATEntryNames(3)->Strings[i]);
             }
         }
//Images used by Units (Construction graphics)
         DataRef = Form1->GetDATFile(0)->GetData();
         NoOfEntries = Form1->GetDATFile(0)->GetOutputEntrycount();
         for (int i=0;i<NoOfEntries;i++) {
             if (NodeID != 0 && NodeID == DataRef[i*Form1->GetDATFile(0)->GetVarcount()+4]) {
                Form1->UsedList->Items->Add("[U"+String(i)+"] "+Form1->GetDATEntryNames(0)->Strings[i]);
             }
         }
}
//Upgrades used by Units
else if (PageIndex == 5) {
        DataRef = Form1->GetDATFile(0)->GetData();
        NoOfEntries = Form1->GetDATFile(0)->GetOutputEntrycount();
        for (int i=0;i<NoOfEntries;i++) {
             if (NodeID == DataRef[i*Form1->GetDATFile(0)->GetVarcount()+25]) {
                Form1->UsedList->Items->Add("[U"+String(i)+"] "+Form1->GetDATEntryNames(0)->Strings[i]);
             }
        }
//Upgrades used by Weapons
        DataRef = Form1->GetDATFile(1)->GetData();
        NoOfEntries = Form1->GetDATFile(1)->GetOutputEntrycount();
        for (int i=0;i<NoOfEntries;i++) {
             if (NodeID == DataRef[i*Form1->GetDATFile(1)->GetVarcount()+6]) {
                Form1->UsedList->Items->Add("[W"+String(i)+"] "+Form1->GetDATEntryNames(1)->Strings[i]);
             }
        }
}
//Techs used by Orders
else if (PageIndex == 6) {
        DataRef = Form1->GetDATFile(10)->GetData();
        NoOfEntries = Form1->GetDATFile(10)->GetOutputEntrycount();
        for (int i=0;i<NoOfEntries;i++) {
             if (NodeID == DataRef[i*Form1->GetDATFile(10)->GetVarcount()+14]) {
                Form1->UsedList->Items->Add("[O"+String(i)+"] "+Form1->GetDATEntryNames(10)->Strings[i]);
             }
        }
//Techs used by Weapons
        DataRef = Form1->GetDATFile(1)->GetData();
        NoOfEntries = Form1->GetDATFile(1)->GetOutputEntrycount();
        for (int i=0;i<NoOfEntries;i++) {
             if (NodeID == DataRef[i*Form1->GetDATFile(1)->GetVarcount()+2]) {
                Form1->UsedList->Items->Add("[W"+String(i)+"] "+Form1->GetDATEntryNames(1)->Strings[i]);
             }
        }
}
//Sounds used by Units
else if (PageIndex == 7) {
        DataRef = Form1->GetDATFile(0)->GetData();
        NoOfEntries = Form1->GetDATFile(0)->GetOutputEntrycount();
        for (int i=0;i<NoOfEntries;i++) {
            if ((i<106 && NodeID == DataRef[i*Form1->GetDATFile(0)->GetVarcount()+29]) || (NodeID >= DataRef[i*Form1->GetDATFile(0)->GetVarcount()+30] && NodeID <= DataRef[i*Form1->GetDATFile(0)->GetVarcount()+31]) || (i<106 && NodeID >= DataRef[i*Form1->GetDATFile(0)->GetVarcount()+32] && NodeID <= DataRef[i*Form1->GetDATFile(0)->GetVarcount()+33]) || (i<106 && NodeID >= DataRef[i*Form1->GetDATFile(0)->GetVarcount()+34] && NodeID <= DataRef[i*Form1->GetDATFile(0)->GetVarcount()+35])) {
               Form1->UsedList->Items->Add("[U"+String(i)+"] "+Form1->GetDATEntryNames(0)->Strings[i]);
            }
        }
}
//Portraits used by Units
else if (PageIndex == 8) {
        DataRef = Form1->GetDATFile(0)->GetData();
        NoOfEntries = Form1->GetDATFile(0)->GetOutputEntrycount();
        for (int i=0;i<NoOfEntries;i++) {
            if (NodeID == DataRef[i*Form1->GetDATFile(0)->GetVarcount()+44]) {
               Form1->UsedList->Items->Add("[U"+String(i)+"] "+Form1->GetDATEntryNames(0)->Strings[i]);
            }
        }
}
//Orders used by Units
else if (PageIndex == 10) {
         DataRef = Form1->GetDATFile(0)->GetData();
         NoOfEntries = Form1->GetDATFile(0)->GetOutputEntrycount();
         for (int i=0;i<NoOfEntries;i++) {
             if (NodeID == DataRef[i*Form1->GetDATFile(0)->GetVarcount()+12] || NodeID == DataRef[i*Form1->GetDATFile(0)->GetVarcount()+13] || NodeID == DataRef[i*Form1->GetDATFile(0)->GetVarcount()+14] || NodeID == DataRef[i*Form1->GetDATFile(0)->GetVarcount()+15] || NodeID == DataRef[i*Form1->GetDATFile(0)->GetVarcount()+16]) {
                Form1->UsedList->Items->Add("[U"+String(i)+"] "+Form1->GetDATEntryNames(0)->Strings[i]);
             }
         }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
This routine checks if there are any DAT files present in a given
directory and loads any that it finds. It reports about the found DATs,
about no-DATs-found and in case the selected directory doesn't exist (what
may happen if the user used the old Load Directory dialog and typed
the directory path himself)
############################################################################
*/
void LoadDATDir (String Directory) {
     bool DATFound=false;
     bool FoundDATs[11];

     if (!DirectoryExists(Directory)) {
        MessageDlg(("The : \""+Directory+"\""+" directory does not exist!").c_str(), mtError, TMsgDlgButtons() << mbOK, 0);
     }
     else {
     //Check if there are any DAT files in the given directory
        for (int i=11;i>=0;i--) {
            FoundDATs[i] = false;
            if (FileExists(Directory+"\\"+GetDATType(i)+".dat")) {
               DATFound = true;
               FoundDATs[i] = true;
            }
        }
        if (DATFound == false) {
           MessageDlg(("No DAT files found in: \""+Directory+"\"").c_str(), mtError, TMsgDlgButtons() << mbOK, 0);
        }
        else if (DATFound == true) {
        //Create a report from the found files 
           String Found;
           bool FirstDAT=true;

           for (int i=0;i<11;i++) {
               if (FoundDATs[i] == true) {
                  if (FirstDAT==true) {
                     Found += GetDATType(i)+".dat";
                     FirstDAT = false;
                  }
                  else if (FirstDAT == false) {
                     Found += ", "+GetDATType(i)+".dat";
                  }
               }
           }
           MessageDlg(("DAT files found in \""+Directory+"\":\n"+Found+".").c_str(), mtInformation, TMsgDlgButtons() << mbOK, 0);

           //Add the directory to the History list
           Form1->AddHistoryItem(Directory);

           //Load the DAT found files 
           for (int i=11;i>=0;i--) {
               if (FoundDATs[i] == true) {
                  CheckDATFile(Directory+"\\"+GetDATType(i)+".dat");
               }
           }
        }
     }
};
//---------------------------------------------------------------------------
/*
############################################################################
This is a simple wrapper used by properties that are controlled by both
a textbox and a dropdown menu. It sets the Target TCombobox's selection
to the given item, or clears the selection if the item's ID is above the
number of elements in the menu.
############################################################################
*/
void SetMenu (TComboBox* Target, unsigned long ItemID) {
if (ItemID != (unsigned long)Target->ItemIndex) {
   if (ItemID < (unsigned long)Target->Items->Count) {
      Target->ItemIndex = ItemID;
   }
   else if (ItemID >= (unsigned long)Target->Items->Count) {
      Target->ItemIndex = -1;
   }
}
};
//---------------------------------------------------------------------------
/*
############################################################################
The same wrapper as above, just overloaded to add additional handling
for properties with associated previews.
The ItemID check from above has been removed because of problems with
drawing the preview if called by the dropdown list itself.
############################################################################
*/
void SetMenu (TComboBox* Target, TImage* TargetPreview, int ItemID) {
   if (ItemID < Target->Items->Count) {
      DrawIcon(ItemID,TargetPreview);
      Target->ItemIndex = ItemID;
   }
   else if (ItemID >= Target->Items->Count) {
      DrawIcon(-1,TargetPreview);
      Target->ItemIndex = -1;
   }
};
//---------------------------------------------------------------------------
