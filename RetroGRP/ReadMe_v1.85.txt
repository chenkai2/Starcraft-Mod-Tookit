-------------------------------------------------------------------
-------------------------------------------------------------------
A Bitmap to StarCraft Sprite Converter v1.85  
by RetroActive  (Jeremy Bake                    jbake@allencomm.com
-------------------------------------------------------------------
-------------------------------------------------------------------
New in v1.85

Well I've added support for 24-bit BMPs this'll make it easier if, like   
me, you export Graphics from 3D Studio MAX.  You no longer have to convert all the   
palettes. Also now you can execute the Program by double-clicking a .GRP file.

Also this can now be made a plug-in for StarDraft's CWAD editor.
Under Plug-ins, Configure Click Add.Type in a name (I usually choose "StarCraft Sprite")
In the Path Edit Box Browse for your copy of RetroGRP.exe  And then in the Filespec: 
Edit Box enter .grp

Now when you open CWAD any GRPs in the cwad can be double clicked
And they will open to be viewed.  (Only viewing is available, until I can   
find out from
Camelot Systems what exactly they'd like to have available.)

One last tip is:  You need to run this once through the EXE before it   
will Work either in the CWAD editor or by double-clicking the .GRP.
Also the first time you run this new version, click the "Reset Locations"
Button and re-run the program (It resets file locations, and hopefully   
clears Any conflict a past version might have written)

This version also lets you preview ALL the frames in the
GRP and not just the first one. 

New in v1.80

Note: something that came up as my buddy was making a GRP.  He saved
	all his bitmaps out and told Paint Shop Pro to set them to
	a specific palette (believing this would make the graphic
	8-bit RLE like it used to) but after compiling the GRP 
	it came out as garbage.  It is VERY important that graphics
	be 8-bit RLE encoded.  the best way to do this (at least 
	with PSP) is to just do a batch conversion (Under the file 
	menu) tell it to resave the files as BMPs but click the options
	button an make sure RLE is checked and not RGB.  Then it will 
	convert them and they should be fine.

One thing I forgot to mention in the last version is that the storm.dll
	that comes with this prog is NOT compatible with StarCraft.
	(Will cause problems to be sure... so I changes the name
	 to Modstorm.dll)
Support for 256 X 256 Graphics (thanks to Acolyte57 for letting
	me know this is possible              Acolyte57@hotmail.com)
a bug that caused graphics with long runs of the same color cause some 
	importing bugs.  this has been fixed.
Dimensions and Number of Icons are now listed below the preview image.
Extralarge graphics no-longer draw outside the preview window.

What's New
///////////////////////////////////////

-<*-<*-<*-<*-<*-<*-<*-<*-<*-<**>-*>-*>-*>-*>-*>-*>-*>-*>-*>-*>-
-* New for version 1.8 *-
-<*-<*-<*-<*-<*-<*-<*-<*-<*-<**>-*>-*>-*>-*>-*>-*>-*>-*>-*>-*>-

you can now preview more than jsut the first frame of a file
the '<'  '>'   buttons move through the file a frame at a time
and the '<<10'  '10>>'  scroll through at 10 frames a push.

the program now associates .grp files with itself
<<<<make sure you run it once without any command line parameters for setup>>>
so a simple double click on a .GRP will open it up

(this also makes it possible to use it as a type 1 plug-in for
Camelot Systems CWAD editor, although it will only let you view files
Palettes will stay at the last loaded palette and <for now> saving out
bitmaps or re-compiling bmps back to a GRP are disabled.)

-<*-<*-<*-<*-<*-<*-<*-<*-<*-<**>-*>-*>-*>-*>-*>-*>-*>-*>-*>-*>-












-* Couple of major enhancements *- v 1.50+

I've now included exporting GRP files directly from
the *.MPQ (thanks to brainspin@hanmail.net for his release
of storming and his modified storm.dll)

you can now set the destination directory where the BMPs get 
written out to.  Instead of defaulting to whereever the GRP 
file was located)

When exporting GRPs from the MPQ you can specify to
either extract in the MPQView style (e.g. unit_zerg_zergling.grp)
or it can create a directory structure under your Output
directory (e.g. <outputdir>\unit\zer\zergling.grp)



Still Coming in the next release (I hope)
/////////////////////////////////////////
fixed version 1.8   -Command Line opening of files

fixed version 1.8   -Being able to view more than the first frame in the Preview area


/////////////////////////////////////////
/////////////////////////////////////////
/////////////////////////////////////////

In case this is your first time reading this I'll recap what
this program does.

Basically this will do two things.
1.  	Takes a .GRP file that's been exported from StarCraft
	with MPQView or one of the like, and exports each
	frame to a .BMP file.

2.	Takes a set of .BMP files and a .RAL file (explained 
	later) file and compresses them back to .GRP format 
	(The new file has x_ pre-pended to it. e.g. 
	cursor_arrow.grp would become x_cursor_arrow.grp.)
	
A few of the restrictions I've found are:	(changes noted below)
	* Will only convert unit graphics only.  No Map tiles yet.
	* The sc_unit.pal must be in the same directory as RetroGRP.exe
	All the BMP files need to be the same resolution (256 colors)
<<<<<<<<BMP files need to be in 8-bit RLE format.>>>>>>>>>>>>>>
	* Sprites cannot exceed 128 X 128 in size.
	   <128> wide still holds true but i've found a few files
	    that are taller, 192 is the biggest i've encountered yet.
	<<<<<<<<Sprites up to 256 X 256 now supported>>>>>>>>>>>>>>>>>>
	I'd reccommend using the StarCraft default palette
	(if you export bmps from a .GRP they'll have the 
	 StarCraft palette attached.)

	I'd recommend using the same number of Frames that appear
	in the .GRP file.  (This one i know isn't required because
	I swapped a carrier in once for the Probe and it ran ok,
	looked silly but it worked.)

Color 0 from the palette is used for transparancy, so don't use it.
It's black but there are plenty of other Very dark colors you can use 
as alternates.

* As far as I can tell palette entries 8-15 are the colors that change
  for team play (so jerseys and such should be colored with these colors). 
	

Explination of .RAL files (as if you couldn't open one and tell)
----------------------------------------------------------------
First is the original .GRP name
followed by a list of bmp files to be re-compressed.
e.g.

cursor_arrow.grp
cursor_arrow000.bmp
dupe_of_cursor_arrow000.bmp
cursor_arrow002.bmp
cursor_arrow003.bmp
...

The numbers don't mean what order they're put in but just how my exporter 
labels them.  They are put in, in the order they appear in the list.
Entries that begin dupe_of_ are duplicate graphics used in the original
GRP file (seems about half of the graphics in a sprite are duplicates)
so if you want to just reuse a previous bitmap from the list, you can 
use this format as well.

Also if you use this for any conversions let me know. I'd love to see 
some of your work.

One last thing...  If you do use this for conversions Please list me in the 
Credits.


*************************************************************************
Now it will convert at least the \unit\thingy directory entries
	although for the tileset directory you'll want to change 
	the palette used before saving out the Bitmaps.

It no longer requires the sc_unit.pal at all!  If it isn't in same directory
	you'll get an error message saying 'an unnamed file was not found'
	if you get this error be sure to load in a palette before loading in
	any GRPs or all the colors in the file will be black.

It now can use either scunit.pal type palettes OR you can load in a JASC
	palette exported from Paint Shop Pro.

Some palette isues to be aware of - the cmdicons.grp file needs to use the 
	Cmdicons_Palette.pal palette (these are the icons that appear at the 
	bottom right of the StarCraft interface and entries between the 
	two palettes overlap.
***********************************************************************



Any suggestions for future improvement (besides Speed I KNOW it needs to 
be A LOT faster).
Or any Bugs or problems email me at 

		jbake@allencomm.com
		Jeremy Bake
		A.K.A.
			
			RetroActive
		       ------>
		           <------  
		                    
Oh and that legal stuff... Like "I'm not responsible if this turns your computer
into a buffalo that tramples you or attracts Aliens who abduct you and melt
your brain" all apply as well...

=)