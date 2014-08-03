fixup-epilog
============

The Epilog Laser Engraver, Running on Windows 8, has some problems.

The driver creates new copies of itself fairly frequently, and you end up with a lot of dead printers.
It is very difficult to tell which printer is the real one.  This is especially true in Adobe Illustrators printer selection dialog.

This "Fixup Epilog.exe" file walks the list of available Epilog Printers, and sets the default to one that is still connected.
