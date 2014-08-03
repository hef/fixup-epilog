Fixup Epilog Laser Engraver
===========================

The Epilog Laser Engraver, Running on Windows 8, has some problems.

The driver creates new copies of itself fairly frequently, and you end up with a lot of dead printers.
It is very difficult to tell which printer is the real one.  This is especially true in Adobe Illustrators printer selection dialog.

This "Fixup Epilog.exe" file walks the list of available Epilog Printers, and sets the default to one that is still connected.

Additionally, the driver is unigned, and the usual approach of installing while in unsigned mode is not reliable,
as it only seems to work for the first copy, and not subsequent copies created outside of unsigned mode.

I had some success signing the driver myself: https://wiki.pumpingstationone.org/HOWTO_Sign_the_Epilog_Mini_Driver

Usage
-----

Just run it.  The program takes no arguments.  It produces debug output, but that can be ignored.


Requirements
------------

Visual C++ Redistributable Packages for Visual Studio 2013: http://www.microsoft.com/en-us/download/details.aspx?id=40784

Developing
----------

I'm working in Visual Studio 2013 Express.
