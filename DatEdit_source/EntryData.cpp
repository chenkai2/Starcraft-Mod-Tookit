//---------------------------------------------------------------------------
#pragma hdrstop
#include "EntryData.h"
#include "Data.h"
#include "grpapi.h"
#include "Options.h"
#include "TForm1.h"
//---------------------------------------------------------------------------
/*
############################################################################
This is a handful DEFINE directive, used just for code clarity, to avoid
repeating the "Form1->" ownership.
############################################################################
*/
#define GetDATFile Form1->GetDATFile
bool SkipMultiDraw=true;
//---------------------------------------------------------------------------
#pragma package(smart_init)
//------------------------------------------------------------------------------
/*
############################################################################
This routine controls the display of the DAT properties in the Editors.
The 'SkipMultiDraw' variable is used to make sure that the preview
graphics are drawn once and only once - which can happen only if this
variable is set to true.
Its construction is two-fold: at firs the general-purpose loop is run,
and then the specific handling follows. Incorporating the specific
routines to the main loop was simply not worth it.
############################################################################
*/

void DisplayEntryData (int EntryID, int PageIndex) {
SkipMultiDraw = true;

TTabSheet *Base;
if (PageIndex != 0) {
   Base = Form1->Editors->Pages[PageIndex];
}
else {
   Base = Form1->UnitTabs->Pages[Form1->GetSubPage()];
}

//Part1: General routine
for (int i=0;i<Base->ControlCount;i++) {
    for (int j=0;j<(((TWinControl*)(Base->Controls[i]))->ControlCount);j++) {
        int HandyVar = ((TWinControl*)(Base->Controls[i]))->Controls[j]->Tag;
        if (HandyVar != -1) {
           TControl* Temp = ((TWinControl*)(Base->Controls[i]))->Controls[j];
           if (String(Temp->ClassName()) == "TEdit") {
              if (abs(HandyVar) > 999) {
                 ((TEdit*)(Temp))->Text = FixVarSize((GetDATFile(PageIndex)->GetData()[EntryID*GetDATFile(PageIndex)->GetVarcount()+(HandyVar-((HandyVar/1000)*1000))])/(HandyVar/1000), (HandyVar-((HandyVar/1000)*1000)),PageIndex);
              }
              else {
                 ((TEdit*)(Temp))->Text = FixVarSize((GetDATFile(PageIndex)->GetData()[EntryID*GetDATFile(PageIndex)->GetVarcount()+HandyVar]), HandyVar,PageIndex);
              }
              if (Form1->FindComponent(((TControl*)(Temp))->Name+"List") != NULL) {
                 int value=0;
                 if (((TEdit*)(Temp))->Text.IsEmpty() == false) {
                    value = ((TEdit*)(Temp))->Text.ToInt();
                 }
                 SetMenu((TComboBox*)(Form1->FindComponent(((TControl*)(Temp))->Name+"List")), value);
              }
           }
           else if (String(Temp->ClassName()) == "TCheckBox") {
              if (abs(HandyVar) > 999) {
                 ((TCheckBox*)(Temp))->Checked = (int(Power(2,float(HandyVar-((HandyVar/1000)*1000))))&GetDATFile(PageIndex)->GetData()[EntryID*GetDATFile(PageIndex)->GetVarcount()+(HandyVar/1000)]);
              }
              else {
                 ((TCheckBox*)(Temp))->Checked = GetDATFile(PageIndex)->GetData()[EntryID*GetDATFile(PageIndex)->GetVarcount()+HandyVar];
              }
           }
           else if (String(Temp->ClassName()) == "TComboBox") {
              ((TComboBox*)(Temp))->ItemIndex = GetDATFile(PageIndex)->GetData()[EntryID*GetDATFile(PageIndex)->GetVarcount()+HandyVar];
           }
        }
    }
}

//Part2: Specific routines
switch (PageIndex) {
          case 0:
               switch (Form1->GetSubPage()) {
                      case 0:
                           {
                           //Special detection of the half supply units
                           int SupProv = GetDATFile(0)->GetData()[EntryID*GetDATFile(0)->GetVarcount()+50];
                           int SupReq = GetDATFile(0)->GetData()[EntryID*GetDATFile(0)->GetVarcount()+51];

                           if ((float(SupProv)/2)-((SupProv)/2) == 0.5) {
                              Form1->UnitSupProv05->Checked = true;
                           }
                           else {
                              Form1->UnitSupProv05->Checked = false;
                           }
                           if ((float(SupReq)/2)-((SupReq)/2) == 0.5) {
                              Form1->UnitSupReq05->Checked = true;
                           }
                           else {
                              Form1->UnitSupReq05->Checked = false;
                           }
                           Form1->UnitTimeSec->Text = (float(Form1->UnitTime->Text.ToInt())/24);
                           }
                           break;
                      case 1:
                           //Only entries from 106-200 (Buildings) have the
                           //Infestation property so they are disabled or the other entries
                           if (EntryID < 106 || EntryID > 201) {
                              Form1->UnitInfestation->Enabled = false;
                              Form1->UnitInfestationList->Enabled = false;
                              Form1->UnitInfestationJump->Enabled = false;
                              Form1->UnitInfestationList->ItemIndex = -1;
                              Form1->UnitInfestation->Text = "";
                              Form1->UnitInfestation->Color = clBtnFace;
                              Form1->UnitInfestationList->Color = clBtnFace;
                           }
                           else if (EntryID >= 106 && EntryID <=201) {
                              Form1->UnitInfestation->Enabled = true;
                              Form1->UnitInfestationList->Enabled = true;
                              Form1->UnitInfestation->Color  = clBlack;
                              Form1->UnitInfestationList->Color  = clBlack;
                              Form1->UnitInfestationJump->Enabled = true;
                           }
                           break;
                      case 2:
                           //Only the first 106 units.dat entries have all sounds available
                           //so they are disabled for the other entries.
	                   if (EntryID >= 106) {
                              Form1->UnitSndReady->Enabled = false;
	                      Form1->UnitSndReady->Text = "";
                              Form1->UnitSndReady->Color = clBtnFace;
                              Form1->UnitSndYesStart->Enabled = false;
                              Form1->UnitSndYesStart->Text = "";
                              Form1->UnitSndYesStart->Color = clBtnFace;
                              Form1->UnitSndYesEnd->Enabled = false;
                              Form1->UnitSndYesEnd->Text = "";
                              Form1->UnitSndYesEnd->Color = clBtnFace;
                              Form1->UnitSndAnnStart->Enabled = false;
                              Form1->UnitSndAnnStart->Text = "";
                              Form1->UnitSndAnnStart->Color = clBtnFace;
                              Form1->UnitSndAnnEnd->Enabled = false;
                              Form1->UnitSndAnnEnd->Text = "";
                              Form1->UnitSndAnnEnd->Color = clBtnFace;

                              Form1->UnitSndReadyList->Enabled = false;
                              Form1->UnitSndReadyList->ItemIndex = -1;
                              Form1->UnitSndReadyList->Color = clBtnFace;
                              Form1->UnitSndYesStartList->Enabled = false;
                              Form1->UnitSndYesStartList->ItemIndex = -1;
                              Form1->UnitSndYesStartList->Color = clBtnFace;
                              Form1->UnitSndYesEndList->Enabled = false;
                              Form1->UnitSndYesEndList->ItemIndex = -1;
                              Form1->UnitSndYesEndList->Color = clBtnFace;
                              Form1->UnitSndAnnStartList->Enabled = false;
                              Form1->UnitSndAnnStartList->ItemIndex = -1;
                              Form1->UnitSndAnnStartList->Color = clBtnFace;
                              Form1->UnitSndAnnEndList->Enabled = false;
                              Form1->UnitSndAnnEndList->ItemIndex = -1;
                              Form1->UnitSndAnnEndList->Color = clBtnFace;
                           }
	                   else if (EntryID < 106) {
                              Form1->UnitSndReady->Enabled = true;
                              Form1->UnitSndReady->Color = clBlack;
                              Form1->UnitSndAnnStart->Enabled = true;
                              Form1->UnitSndAnnStart->Color = clBlack;
                              Form1->UnitSndAnnEnd->Enabled = true;
                              Form1->UnitSndAnnEnd->Color = clBlack;
                              Form1->UnitSndYesStart->Enabled = true;
                              Form1->UnitSndYesStart->Color = clBlack;
                              Form1->UnitSndYesEnd->Enabled = true;
                              Form1->UnitSndYesEnd->Color = clBlack;

                              Form1->UnitSndReadyList->Enabled = true;
                              Form1->UnitSndReadyList->Color = clBlack;
                              Form1->UnitSndAnnStartList->Enabled = true;
                              Form1->UnitSndAnnStartList->Color = clBlack;
                              Form1->UnitSndAnnEndList->Enabled = true;
                              Form1->UnitSndAnnEndList->Color = clBlack;
                              Form1->UnitSndYesStartList->Enabled = true;
                              Form1->UnitSndYesStartList->Color = clBlack;
                              Form1->UnitSndYesEndList->Enabled = true;
                              Form1->UnitSndYesEndList->Color = clBlack;
                           }
                           break;
                      case 3:
                           //Only entries from 106-200 (Buildings) have the
                           //addon-placement property so they are disabled or the other entries
	                   if (EntryID < 106 || EntryID > 201) {
                              Form1->UnitAddPosX->Enabled = false;
                              Form1->UnitAddPosY->Enabled = false;
                              Form1->UnitAddPosX->Color = clBtnFace;
                              Form1->UnitAddPosY->Color = clBtnFace;
                              Form1->UnitAddPosX->Text = "";
                              Form1->UnitAddPosY->Text = "";
                           }
	                   else if (EntryID >= 106 && EntryID <=201) {
                              Form1->UnitAddPosX->Enabled = true;
                              Form1->UnitAddPosY->Enabled = true;
                              Form1->UnitAddPosX->Color = clBlack;
                              Form1->UnitAddPosY->Color = clBlack;
                           }
                           if (Form1->Options.UnitSizePreviewType != 0) {
                              DrawUnitSize(EntryID,Form1->UnitDimLeft->Text.ToInt(),Form1->UnitDimUp->Text.ToInt(),Form1->UnitDimRight->Text.ToInt(),Form1->UnitDimDown->Text.ToInt());
                           }
                           break;
               }
               break;
          case 1:
               DrawIcon(GetDATFile(1)->GetData()[EntryID*GetDATFile(1)->GetVarcount()+23],Form1->WeapIconPrev);
               break;
          case 3:
               if (EntryID < 130) {
	          Form1->SpriteHPBar->Text = "";
	          Form1->SpriteHPBar->Enabled = false;
	          Form1->SpriteHPBar->Color = clBtnFace;
                  Form1->HPBarPrev->Visible = false;
                  Form1->SpriteHPBarbox->Text = "";
                  Form1->SpriteHPBarbox->Color = clBtnFace;
                  Form1->SpriteHPBarboxUpDown->Enabled = false;
                  Form1->SpriteSelCircle->Text = "";
	          Form1->SpriteSelCircle->Enabled = false;
	          Form1->SpriteSelCircle->Color = clBtnFace;
                  Form1->SpriteSelCircleList->ItemIndex = -1;
	          Form1->SpriteSelCircleList->Enabled = false;
	          Form1->SpriteSelCircleList->Color = clBtnFace;
	          Form1->SpriteCircleOff->Text = "";
                  Form1->SpriteCircleOff->Enabled = false;
                  Form1->SpriteCircleOff->Color = clBtnFace;
                  Form1->SpriteSelCircleJump->Enabled = false;
                  Form1->CirclePrev->Visible = false;
                  Form1->CircleUnitPrev->Visible = false;
                  //If the drawing function is called with the index parameter 0xFFFF
                  //(which is not possible for this property, since it's 1-byte long)
                  //the selection circle preview image is hidden.
                  if (Form1->Options.ShowSelCirclePreview == true) {
                     DrawSelCircle(EntryID, 0xFFFF, 0);
                  }
               }
               else if (EntryID >= 130) {
                  Form1->SpriteHPBar->Enabled = true;
                  Form1->SpriteHPBar->Color = clBlack;
                  Form1->HPBarPrev->Visible = true;
                  Form1->SpriteHPBarbox->Color = clBlack;
                  Form1->SpriteHPBarbox->Text = (Form1->SpriteHPBar->Text.ToInt()-1)/3;
                  Form1->SpriteHPBarboxUpDown->Position = Form1->SpriteHPBarbox->Text.ToInt();
                  Form1->SpriteHPBarboxUpDown->Enabled = true;
      	          Form1->SpriteSelCircle->Enabled = true;
	          Form1->SpriteSelCircle->Color = clBlack;
	          Form1->SpriteSelCircleList->Enabled = true;
                  Form1->SpriteSelCircleList->Color = clBlack;
	          Form1->SpriteCircleOff->Enabled = true;
	          Form1->SpriteCircleOff->Color  = clBlack;
                  Form1->SpriteSelCircleJump->Enabled = true;
                  if (Form1->Options.ShowSelCirclePreview == true) {
                     Form1->CirclePrev->Visible = true;
                     DrawSelCircle(EntryID, Form1->SpriteSelCircle->Text.ToInt(),Form1->SpriteCircleOff->Text.ToInt());
                     DrawHPBar(Form1->SpriteHPBar->Text.ToInt());
                     Form1->HPBarPrev->Repaint();
                  }
               }
               break;
          case 4:
               switch (GetDATFile(4)->GetData()[EntryID*GetDATFile(4)->GetVarcount()+8]) {
                      case 0:
                           Form1->ImgShieldOL->ItemIndex=0;
                           break;
                      case 2:
                           Form1->ImgShieldOL->ItemIndex=2;
                           break;
                      case 133:
                           Form1->ImgShieldOL->ItemIndex=1;
                           break;
                      case 184:
                           Form1->ImgShieldOL->ItemIndex=3;
                           break;
               }
               break;
          case 5:
               Form1->UpgTimeSec->Text = (float(Form1->UpgTime->Text.ToInt())/24);
               Form1->UpgFactorTimeSec->Text = (float(Form1->UpgFactorTime->Text.ToInt())/24);
               DrawIcon(GetDATFile(5)->GetData()[EntryID*GetDATFile(5)->GetVarcount()+7],Form1->UpgIconPrev);
               break;
          case 6:
               Form1->TechTimeSec->Text = (float(Form1->TechTime->Text.ToInt())/24);
               DrawIcon(GetDATFile(6)->GetData()[EntryID*GetDATFile(6)->GetVarcount()+5],Form1->TechIconPrev);
               break;
          case 10:
               DrawIcon(GetDATFile(10)->GetData()[EntryID*GetDATFile(10)->GetVarcount()+16],Form1->OrdHighlightPrev);
               break;
}
SkipMultiDraw=false;
};
//------------------------------------------------------------------------------
/*
############################################################################
The following routine keeps track of the changes of a particular DAT
properties and apply the changes to the data stored in the memory.
Properties that are controlled by both a textbox and a dropdown list
use the SetMenu() function to control what is shown in the dropdown list.

Just like the displaying routine above, this routine is also two-fold:
first goes the general-purpose loop, and then the specific handling follows.

Note: The Tag property of an interface control indicates the ID of the
property it is associated with. Tag value higher than 999 indicates that
the value used in the interface must be processed and is stored in a
different form in the data table.

############################################################################
*/

void ChangeEntryData (int EntryID,int PageIndex,unsigned int value,TObject* Target) {

int HandyVar = ((TWinControl*)(Target))->Tag;
if (String(Target->ClassName()) == "TEdit") {
   if (abs(HandyVar) > 999) {
      GetDATFile(PageIndex)->GetData()[EntryID*GetDATFile(PageIndex)->GetVarcount()+(HandyVar-((HandyVar/1000)*1000))] = value*(HandyVar/1000);
   }
   else {
      GetDATFile(PageIndex)->GetData()[EntryID*GetDATFile(PageIndex)->GetVarcount()+HandyVar] = value;
      if (Form1->FindComponent(((TControl*)(Target))->Name+"List") != NULL) {
         SetMenu((TComboBox*)(Form1->FindComponent(((TControl*)(Target))->Name+"List")), value);
      }
   }
}
else if (String(Target->ClassName()) == "TCheckBox") {
     if (abs(HandyVar) > 999) {
        if (value == 1) {
           (GetDATFile(PageIndex)->GetData()[EntryID*GetDATFile(PageIndex)->GetVarcount()+(HandyVar/1000)])|=((int)(Power(2,float(int(HandyVar-((HandyVar/1000)*1000))))));
        }
        else {
           (GetDATFile(PageIndex)->GetData()[EntryID*GetDATFile(PageIndex)->GetVarcount()+(HandyVar/1000)])&=~((int)(Power(2,float(int(HandyVar-((HandyVar/1000)*1000))))));
        }
     }
     else {
        GetDATFile(PageIndex)->GetData()[EntryID*GetDATFile(PageIndex)->GetVarcount()+HandyVar] = bool (value);
     }
}
else if (String(Target->ClassName()) == "TComboBox") {
     if (HandyVar == -1 && ((TControl*)(Target))->Name.Pos("List") != 0) {
        ((TEdit*)(Form1->FindComponent( ((TControl*)(Target))->Name.SubString(1,((TControl*)(Target))->Name.Length()-4))))->Text = value;
     }
     else {
        GetDATFile(PageIndex)->GetData()[EntryID*GetDATFile(PageIndex)->GetVarcount()+HandyVar] = value;
     }
}

switch (PageIndex) {
          case 0:
               switch (Form1->GetSubPage()) {
                      case 0:
                           if (Target ==Form1->UnitSupProv05) {
                              if (Form1->UnitSupProv05->Checked == true) {
                                 GetDATFile(0)->GetData()[EntryID*GetDATFile(0)->GetVarcount()+50]++;
                              }
                              else {
                                 GetDATFile(0)->GetData()[EntryID*GetDATFile(0)->GetVarcount()+50]--;
                              }
                           }
                           else if (Target ==Form1->UnitSupReq05) {
                              if (Form1->UnitSupReq05->Checked == true) {
                                 GetDATFile(0)->GetData()[EntryID*GetDATFile(0)->GetVarcount()+51]++;
                              }
                              else {
                                 GetDATFile(0)->GetData()[EntryID*GetDATFile(0)->GetVarcount()+51]--;
                              }
                           }
                           else if (Target ==Form1->UnitSupProv) {
                              GetDATFile(0)->GetData()[EntryID*GetDATFile(0)->GetVarcount()+50] = (unsigned char) (((unsigned char) Form1->UnitSupProv->Text.ToInt())*2+int(Form1->UnitSupProv05->Checked));
                           }
                           else if (Target ==Form1->UnitSupReq) {
                              GetDATFile(0)->GetData()[EntryID*GetDATFile(0)->GetVarcount()+51] = (unsigned char) (((unsigned char) Form1->UnitSupReq->Text.ToInt())*2+int(Form1->UnitSupReq05->Checked));
                           }
                           break;
                      case 3:
                           if (Target ==Form1->UnitPortrait) {
                              if (value == 0xFFFF) {
	                         SetMenu(Form1->UnitPortraitList,220);
                              }
                              else {
                                 SetMenu(Form1->UnitPortraitList,(unsigned short) value);
                              }
                           }
                           break;
               }
               break;
          case 1:
               if (SkipMultiDraw == false && Target == Form1->WeapIcon) {
	          SetMenu(Form1->WeapIconList,Form1->WeapIconPrev,(unsigned short) value);
               }
               break;
          case 3:
               if (Target == Form1->SpriteImage) {
                  if (SkipMultiDraw == false && EntryID >= 130 && Form1->Options.ShowSelCirclePreview == true) {
                     DrawSelCircle(EntryID,GetDATFile(3)->GetData()[(EntryID)*GetDATFile(3)->GetVarcount()+4] ,GetDATFile(3)->GetData()[(EntryID)*GetDATFile(3)->GetVarcount()+5]);
                  }
                  else if (SkipMultiDraw == false && EntryID < 130 && Form1->Options.ShowSelCirclePreview == true) {
                     DrawSelCircle(EntryID, 0xFFFF, 0);
                  }
               }
               if (EntryID >= 130) {
                  if (Target == Form1->SpriteSelCircle) {
                     if (SkipMultiDraw == false && EntryID >= 130 && Form1->Options.ShowSelCirclePreview == true) {
                        DrawSelCircle(EntryID,(unsigned char) value ,GetDATFile(3)->GetData()[(EntryID)*GetDATFile(3)->GetVarcount()+5]);
                     }
                     else if (SkipMultiDraw == false && EntryID < 130 && Form1->Options.ShowSelCirclePreview == true) {
                        DrawSelCircle(EntryID, 0xFFFF, 0);
                     }
                  }
                  else if (Target == Form1->SpriteCircleOff) {
                     if (SkipMultiDraw == false && EntryID >= 130 && Form1->Options.ShowSelCirclePreview == true) {
                        DrawSelCircle(EntryID,GetDATFile(3)->GetData()[(EntryID)*GetDATFile(3)->GetVarcount()+4], (unsigned char) value);
                     }
                     else if (SkipMultiDraw == false && EntryID < 130 && Form1->Options.ShowSelCirclePreview == true) {
                        DrawSelCircle(EntryID, 0xFFFF, 0);
                     }
                  }
               }
               break;
          case 4:
               if (Target == Form1->ImgShield) {
                  switch (value) {
                         case 0:
                              Form1->ImgShieldOL->ItemIndex=0;
                              break;
                         case 133:
                              Form1->ImgShieldOL->ItemIndex=1;
                              break;
                         case 2:
                              Form1->ImgShieldOL->ItemIndex=2;
	                      break;
                         case 184:
                              Form1->ImgShieldOL->ItemIndex=3;
                              break;
                         default:
                              Form1->ImgShieldOL->ItemIndex=-1;
                              break;
                  }
               }
               else if (Target == Form1->ImgShieldOL) {
                    switch (Form1->ImgShieldOL->ItemIndex) {
                           case 0:
                                Form1->ImgShield->Text=0;
                                break;
                           case 1:
                                Form1->ImgShield->Text=133;
                                break;
                           case 2:
                                Form1->ImgShield->Text=2;
		                break;
                           case 3:
		                Form1->ImgShield->Text=184;
                                break;
                    }
               }
               break;
          case 5:
	       if (Target == Form1->UpgTime) {
                  Form1->UpgTimeSec->Text = (float(value)/24);
               }
	       else if (Target == Form1->UpgFactorTime) {
                  Form1->UpgFactorTimeSec->Text = (float(value)/24);
               }
               else if (SkipMultiDraw == false && Target == Form1->UpgIcon) {
	          SetMenu(Form1->UpgIconList,Form1->UpgIconPrev,(unsigned short) value);
               }
               break;
          case 6:
	       if (Target == Form1->TechTime) {
                  Form1->TechTimeSec->Text = (float(value)/24);
               }
               else if (SkipMultiDraw == false && Target == Form1->TechIcon) {
	          SetMenu(Form1->TechIconList,Form1->TechIconPrev,(unsigned short) value);
               }
               break;
}
};
//------------------------------------------------------------------------------
/*
############################################################################
This function draws a specific icon on a given TImage control, both
supplied as parameters. There is a black rectangle (FillRect) drawn
prior to the GRP frame itself. This is because of the way transparency
works with TImage components and the necessity to 'manually' clear
out the background using the said rectangle.
############################################################################
*/
void DrawIcon(int IconIndex,TImage *TargetPreview) {
     unsigned long PalBuffer[256];
     void *GRPBuffer;

     TargetPreview->Visible = true;
     TargetPreview->Canvas->Brush->Color = clBlack;
     TargetPreview->Canvas->FillRect(Rect(0,0,32,32));
     if (Form1->GetIconIsMPQImport() == false) {
        GRPBuffer = Form1->Icons.Data;
     }
     else if (Form1->GetIconIsMPQImport() == true) {
        GRPBuffer = Form1->MpqIcons.Data;
     }
     if (IconIndex >=0 && IconIndex < ((unsigned short*)(GRPBuffer))[0]) {
        if (GRPBuffer != NULL) {
           LoadPalette(String(Form1->GetProgPath()+"Default\\IconPal.pal").c_str(), PalBuffer);

           //Get the actual frame size information to center the preview properly
           unsigned long left, top, width, height;
           GetGrpFrameInfo(GRPBuffer, IconIndex, &left, &top, &width, &height);
           DrawGrp(GRPBuffer, TargetPreview->Canvas->Handle, abs(TargetPreview->Width-width)/2, abs(TargetPreview->Height-height)/2, IconIndex, PalBuffer, 0,0);
        }
        else {
           MessageDlg("Failed to load the GRP file with icons.", mtError, TMsgDlgButtons() << mbOK, 0);
        }
     }
};
//------------------------------------------------------------------------------
/*
############################################################################
This routine draws the Unit Size Preview in the Graphics tab of the
Units Editor. The reference point is put exactly at the center of the
Preview panel and the size rectangle and the unit GRP preview are also
centered to the same point.
############################################################################
*/

void DrawUnitSize(int EntryID,int ViewLeft,int ViewUp,int ViewRight,int ViewDown) {
int SizeLeft = ViewLeft;
int SizeUp = ViewUp;
int SizeRight = ViewRight;
int SizeDown = ViewDown;

Form1->SizeRefPoint->Left = (Form1->UnitDimView->Width)/2;
Form1->SizeRefPoint->Top = (Form1->UnitDimView->Height)/2;

Form1->SizeRect->Width = SizeLeft+SizeRight;
Form1->SizeRect->Height = SizeUp+SizeDown;
Form1->SizeRect->Left = (Form1->UnitDimView->Width)/2;
Form1->SizeRect->Top = ((Form1->UnitDimView->Height)/2);
if (SizeUp==1 && SizeDown==1) {
   Form1->SizeRect->Top = (Form1->UnitDimView->Height)/2;
}
else if (SizeLeft==1 && SizeUp==1) {
   Form1->SizeRect->Left = (Form1->UnitDimView->Width)/2;
}
else {
   Form1->SizeRect->Top = (Form1->UnitDimView->Height)/2+1-SizeUp;
   Form1->SizeRect->Left = (Form1->UnitDimView->Width)/2+1-SizeLeft;
}
Form1->SizeRect->Visible = true;
Form1->SizeRefPoint->Visible = true;

if (Form1->Options.UnitSizePreviewType == 2) {
   unsigned long PalBuffer[256],BytesRead;
   void *FileHandle;
   if (Form1->ImgGRPList->Items->Count == 0) {
      LoadTBLList(Form1->ImgGRPList,"images");
   }
   int GRPID = GetDATFile(4)->GetData()[GetDATFile(3)->GetData()[GetDATFile(2)->GetData()[GetDATFile(0)->GetData()[EntryID*GetDATFile(0)->GetVarcount()]*GetDATFile(2)->GetVarcount()]*GetDATFile(3)->GetVarcount()]*GetDATFile(4)->GetVarcount()];
   bool Draw=false;
   String FileName="";
   if (GRPID == 0) {
      Form1->SizeGRPPrev->Canvas->Brush->Color = clBtnFace;
      Form1->SizeGRPPrev->Canvas->FillRect(Rect(0,0,256,256));
   }
   else if (GRPID >= 1) {
      FileName = String("unit\\"+Form1->ImgGRPList->Items->Strings[GRPID]);
      FileName = FileName.SubString(1,FileName.Length()-3).Delete(FileName.Pos(String(GRPID)),String(GRPID).Length()+1);
      if (SFileOpenFileEx(NULL,FileName.c_str(),NULL,&FileHandle) != false) {
         int FileSize = SFileGetFileSize(FileHandle,NULL);
         unsigned char *FileBuffer = new unsigned char [FileSize];

         if (FileBuffer) {
            if (SFileReadFile(FileHandle,(void **)FileBuffer,FileSize,&BytesRead,NULL)) {
               unsigned short GRPWidth = FileBuffer[2]+256*FileBuffer[3];
               unsigned short GRPHeight = FileBuffer[4]+256*FileBuffer[5];
               unsigned char FrameLeft = FileBuffer[6];
               unsigned char FrameTop = FileBuffer[7];

               Form1->SizeGRPPrev->Left = ((Form1->UnitDimView->Width-GRPWidth)/2)+FrameLeft;
               Form1->SizeGRPPrev->Top = ((Form1->UnitDimView->Height-GRPHeight)/2)+FrameTop;
               Form1->SizeGRPPrev->Canvas->Brush->Color = clBtnFace;
               Form1->SizeGRPPrev->Canvas->FillRect(Rect(0,0,256,256));

               String PalFile;
               if (FileName.Pos("neutral") != 0 || FileName.Pos("tileset") != 0) {
                  PalFile = "Terrain";
               }
               else {
                  PalFile = "Units";
               }
               LoadPalette(String(Form1->GetProgPath()+"Default\\"+PalFile+".pal").c_str(), PalBuffer);
               DrawGrp(FileBuffer, Form1->SizeGRPPrev->Canvas->Handle, 0-FrameLeft, 0-FrameTop, 0, PalBuffer, 0, 0);
               Draw = true;
            }
         }
         delete FileBuffer;
      }
   }
   SFileCloseFile(FileHandle);
   if (Draw == false && GRPID >= 1) {
      MessageDlg("The GRP file: \""+FileName+"\" was not found in the Starcraft MPQs, sorry", mtError, TMsgDlgButtons() << mbOK, 0);
   }
}
};
//------------------------------------------------------------------------------
/*
############################################################################
This routine draws the Selection Circle Preview over a sprite's graphics
in the Sprites Editor.
############################################################################
*/

void DrawSelCircle(int EntryID,int CircleID,int CircleOff) {
unsigned long PalBuffer[256],BytesRead=0;
void *FileHandle;
Form1->CircleUnitPrev->Visible = true;
Form1->CirclePrev->Tag=0;
bool UnitDraw=false;

if (Form1->ImgGRPList->Items->Count == 0) {
   LoadTBLList(Form1->ImgGRPList,"images");
}
              
if (CircleID != 0xFFFF) {
   Form1->CirclePrev->Visible = true;
   bool CircleDraw=false;
   int CircleGRPID = GetDATFile(4)->GetData()[(561+CircleID)*GetDATFile(4)->GetVarcount()];
   String CircleName = "";
   if (CircleGRPID == 0) {
      Form1->CirclePrev->Canvas->Brush->Color = clBtnFace;
      Form1->CirclePrev->Canvas->FillRect(Rect(0,0,256,256));
   }
   else if (CircleGRPID >= 1) {
      CircleName = String("unit\\"+Form1->ImgGRPList->Items->Strings[CircleGRPID]);
      CircleName = CircleName.SubString(1,CircleName.Length()-3).Delete(CircleName.Pos(String(CircleGRPID)),String(CircleGRPID).Length()+1);
      if (SFileOpenFileEx(NULL,CircleName.c_str(),NULL,&FileHandle) != false) {
         int FileSize = SFileGetFileSize(FileHandle,NULL);
         unsigned char *FileBuffer = new unsigned char [FileSize];

         if (FileBuffer) {
            if (SFileReadFile(FileHandle,(void **)FileBuffer,FileSize,&BytesRead,NULL)) {
               unsigned short GRPWidth = FileBuffer[2]+256*FileBuffer[3];
               unsigned short GRPHeight = FileBuffer[4]+256*FileBuffer[5];
               unsigned char FrameLeft = FileBuffer[6];
               unsigned char FrameTop = FileBuffer[7];

               Form1->CirclePrev->Left = ((Form1->CircleView->Width-GRPWidth)/2)+FrameLeft;
               Form1->CirclePrev->Top = ((Form1->CircleView->Height-GRPHeight)/2)+FrameTop+CircleOff;
               Form1->CirclePrev->Tag=FileBuffer[9];

               Form1->CirclePrev->Canvas->Brush->Color = clBtnFace;
               Form1->CirclePrev->Canvas->FillRect(Rect(0,0,256,256));

               LoadPalette(String(Form1->GetProgPath()+"Default\\Units.pal").c_str(), PalBuffer);
               DrawGrp(FileBuffer, Form1->CirclePrev->Canvas->Handle, 0-FrameLeft, 0-FrameTop, 0, PalBuffer, 0, 0);
               CircleDraw = true;
            }
         }
         delete FileBuffer;
      }
   }
   SFileCloseFile(FileHandle);
   if (CircleDraw == false && CircleGRPID >= 1) {
      MessageDlg("The GRP file: \""+CircleName+"\" was not found in the Starcraft MPQs, sorry", mtError, TMsgDlgButtons() << mbOK, 0);
   }
}

int GRPID = GetDATFile(4)->GetData()[GetDATFile(3)->GetData()[EntryID*GetDATFile(3)->GetVarcount()]*GetDATFile(4)->GetVarcount()];
String FileName="";
if (GRPID == 0) {
   Form1->CircleUnitPrev->Canvas->Brush->Color = clBtnFace;
   Form1->CircleUnitPrev->Canvas->FillRect(Rect(0,0,256,256));
}
else if (GRPID >= 1) {
   FileName = String("unit\\"+Form1->ImgGRPList->Items->Strings[GRPID]);
   FileName = FileName.SubString(1,FileName.Length()-3).Delete(FileName.Pos(String(GRPID)),String(GRPID).Length()+1);
   if (SFileOpenFileEx(NULL,FileName.c_str(),NULL,&FileHandle) != false) {
      int FileSize = SFileGetFileSize(FileHandle,NULL);
      unsigned char *FileBuffer = new unsigned char [FileSize];

      if (FileBuffer) {
         if (SFileReadFile(FileHandle,(void **)FileBuffer,FileSize,&BytesRead,NULL)) {
            unsigned short GRPWidth = FileBuffer[2]+256*FileBuffer[3];
            unsigned short GRPHeight = FileBuffer[4]+256*FileBuffer[5];
            unsigned char FrameLeft = FileBuffer[6];
            unsigned char FrameTop = FileBuffer[7];

            Form1->CircleUnitPrev->Left = ((Form1->CircleView->Width-GRPWidth)/2)+FrameLeft;
            Form1->CircleUnitPrev->Top = ((Form1->CircleView->Height-GRPHeight)/2)+FrameTop;
            Form1->CircleUnitPrev->Canvas->Brush->Color = clBtnFace;
            Form1->CircleUnitPrev->Canvas->FillRect(Rect(0,0,256,256));

            String PalFile="";
            if (FileName.Pos("neutral") != 0 || FileName.Pos("tileset") != 0) {
               PalFile = "Terrain";
            }
            else {
               PalFile = "Units";
            }
            LoadPalette(String(Form1->GetProgPath()+"Default\\"+PalFile+".pal").c_str(), PalBuffer);
            DrawGrp(FileBuffer, Form1->CircleUnitPrev->Canvas->Handle, 0-FrameLeft, 0-FrameTop, 0, PalBuffer, 0,0);
            UnitDraw = true;
         }
      }
      delete FileBuffer;
   }
}
if (UnitDraw == false && GRPID >= 1) {
   MessageDlg("The GRP file: \""+FileName+"\" was not found in the Starcraft MPQs, sorry", mtError, TMsgDlgButtons() << mbOK, 0);
}
};
//------------------------------------------------------------------------------
/*
############################################################################
This routine draws the Health bar in the Sprites Editor, given a specific
bar length, recalculated the way it works in SC.
############################################################################
*/

void DrawHPBar (int HPBarLength) {
     Form1->HPBarPrevPanel->Width = HPBarLength;
     Form1->HPBarPrevPanel->Left = (Form1->CircleView->Width-Form1->HPBarPrev->Width)/2;
     Form1->HPBarPrevPanel->Top = (Form1->CirclePrev->Top+Form1->CirclePrev->Tag+5);
     Form1->HPBarPrevPanel->Height = 5;
     Form1->HPBarPrevPanel->BringToFront();     
     Form1->HPBarPrev->Canvas->Brush->Color = clBlack;
     Form1->HPBarPrev->Canvas->Pen->Color = clBlack;
     Form1->HPBarPrev->Canvas->FillRect(TRect(0,0,Form1->HPBarPrev->Width,Form1->HPBarPrev->Height));
     Form1->HPBarPrev->Canvas->Brush->Color = clGreen;
     Form1->HPBarPrev->Canvas->Pen->Color = clGreen;
     for (int i=0;i<(HPBarLength-1)/3;i++) {
         Form1->HPBarPrev->Canvas->FillRect(TRect(1+i*3,1,3+i*3,4));
     }
};
//------------------------------------------------------------------------------

