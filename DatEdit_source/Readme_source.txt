########################################################
DATEDIT SOURCE README
Created by BroodKiller (Jacek Kominek) 2005-2008
Contact: broodkiller@gmail.com
########################################################

---------------------------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
---------------------------------------------------------------------------------------

---===Installation Notes===---
1)Unpack the archive using your favourite program
2)Run the project file (BPR)

---===Usage Notes===---
0)In order to do anything with this source package, you need at least Borland C++ Builder 6. It was developped with the Personal distribution of this IDE, so there should be no problem with Professional and Enterprise distributions. I haven't tested it on previous versions of BCB, but my guess is that there could be problems, so avoid using them if possible. This package should work and build properly under Borland Developper Studio (Architect distribution) too. I would almost develop DatEdit 1.5 completely with BDS, but since I started in BCB6 and didn't really need anything from the new BDS, I decided to go with the good ol' BCB6 until the very end.
Making head or tail out of this package requires semi-intermediate proficiency with C++ (which means you should be past "Hello World!" and "class MyClass") and familiarity with the BCB Visual Component Library. No advanced concepts like templates, extensive inheritance, or OLE were used here, but you should know how to work with classes and loops, as well as be familiar with custom data types. DAT format knowledge will also pay back.


1)As indicated within the main.cpp file, please show a bit of understanding to this code. I was learning both C++ programming and VCL all along its development, and as such - things could get pretty messy down there. Feel free to contact me if you have some questions regarding the program, its working and functionality. Please, DO NOT contact me with complains regarding the code, I have stopped developping it. 


2)I tried to be as informative as possible throughout the code, so variables, functions and classes pretty much do what their names say. However, variable names DO NOT contain the variable's type, so if you're stuck - try looking around if you don't know what a certain variable type's is. Outside from the the DAT-associated routines, numerical variables are most often of type 'int', and text variables are of type 'String' (short for 'Ansistring'). 


3)As you will most probably notice, a core piece of the whole program is reusable code. I tried to handle similar problems within the scope of one routine, mostly by resorting to custom parameters. This however sometimes required me to store certain values in the program. Since I am not a big fan of using globals or some custom tables for this purpose, I made extensive use of VCL components properties, mostly the integer "Tag" property, simplifying A LOT this way. Some people may like this, some probably won't. I do :)


4)The code is stored in several different files. Here's a quick rundown of their content:

About.cpp - The "About DatEdit" form. Nothing really hapenning there, except automated mailing.

Credits.cpp - The "DatEdit Credits" form. Same thing, nothing but a listing of people who helped me develop the program.

Data.cpp - This file contains everything that I couldn't find place for anywhere else. It mostly contains short general purpose "Get" functions to map certain interface-originating values (like list indexes etc.) to other values (like DAT names, or other strings). It also contains 2 important file-handling functions, CheckDATFile() and CheckMPQFile(), that read from a data source, and a MPQ-exporting function;

DatEdit.cpp - Nothing here, just the main program loop.

DoodadInfo.cpp - The "Doodad info" form.

EntryData.cpp - This file contains 2 very important routines: one that handle displaying a DAT entry's data on the interface, and another that handles the reverse process - storing user input in appropriate data structures. It also contains a few functions responsible for drawing specific graphics on the interface (unit size preview, Icon preview, Sprites GRP and HP bar previews)

ExportBox.cpp - the "Export File(s)..." form. Nothing except the basic export list handling.

FileCompare.cpp - The "Compare/Merge Files..." form. Controls both functionalites (comparing and merging) and data output into the table.

FileData.cpp - This file contains all definitions for members of the crucial 'FileData' class, used to store DAT data.

Funcs.cpp - Code included in this file was written by DiscipleOfAdun, and not me. It must do some important things though, I think ;) (Seriously, this file stores functions involved in creating the FireGraft-based self-executing MPQ patches)

LoadDir.cpp - A custom "Open Directory" form, used if the user selects the appropriate option.

LoadList.cpp - A collection of several functions responsible for parsing and loading some source lists onto the interface components, loading the "Used by" list and loading an entire directory of DAT files.

Main.cpp - The heart of the program's interfacing. Contains A LOT of interface components-associated event handlers and custom actions.

MergeSource.cpp - The "Select Merge source" form, used with the "Always Ask" merging option.

Options.cpp - The "Options" form and its associated functionality, custom file handling and Links.

ProgressForm.cpp - A small progress bar, used during MPQ exporting for example. It is stored as a separate form because VCL did not like my way of implementing directly ON the interface :P

SavePatch.cpp - Again a source by DiscipleOfAdun. It too is involved in interfacing with the self-executable patch creating process.

Splash.cpp  - duh...the splash screen form?

TBLParser.cpp - TBL parsing and <X> tag-style conversion routine.

TForm1.cpp - This file contains definition for the custom members of the main program's class. Used to be stored in the 'Main.cpp' file, but it was getting too big and I moved them outside.


5)The Project DOES NOT use Dynamic RTL, and it DOES NOT build with runtime packages. Thus, it can operate on its own, and thus it is this big ;) It makes use of both ShadowFlare's data-handling libraries SFMPQAPI and GRPAPI however, which means that they cannot be omitted (unless someone decides to build them statically into the program)


6)Apart from the obvious things like menus etc, NO data is hardcoded within the program - everything is dynamically loaded from external files: entry names, property lables, property values lists, TBL strings, everything. This highly versatile construction allowed for very big ease in fixing any mistakes in this regard.


7)I use "i" as the for-loop counter, so what? Much better than "Id","loopNo" or....brrr..."count"!


8)The code is pretty much completely commented, however I didn't include many function-body comments, but resorted to general descriptions what a particular function does. I know this isn't very helpful, but if you know some VCL and DAT formats then the code should not pose any more problems than any foreign code. In case you don't know VCL, then BCB has excellent VCL documentation, and in case you're not at least familiar with DAT formats, then what are you doing here? ;) (file formats are stored in a separate "Formats" directory)


I guess that's about it :)
-Jacek "BroodKiller" Kominek