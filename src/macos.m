/*
  macos.m

  Copyright (c) 2022
  http://www.tuxpaint.org/

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
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
  (See COPYING.txt)
*/

#import <Cocoa/Cocoa.h>
#import <libintl.h>
#import "macos.h"


static void setupApplicationMenu(void)
{
    /*
    * Forked from SDLMain.m that comes with the SDL source code that comes with
    * MacPorts.  Credits to Darrell Walisser <dwaliss1@purdue.edu> and Max Horn
    * <max@quendi.de>.
    */

    /* warning: this code is very odd */
    NSMenu *appleMenu;
    NSMenuItem *menuItem;
    NSString *title;

    appleMenu = [[NSMenu alloc] initWithTitle:@""];

    /* Add menu items */
    title = [NSString stringWithUTF8String:gettext("About Tux Paint")];
    [appleMenu addItemWithTitle:title action:@selector(orderFrontStandardAboutPanel:) keyEquivalent:@""];

    [appleMenu addItem:[NSMenuItem separatorItem]];

    title = [NSString stringWithUTF8String:gettext("Hide Tux Paint")];
    [appleMenu addItemWithTitle:title action:@selector(hide:) keyEquivalent:@"h"];

    menuItem = (NSMenuItem *)[appleMenu addItemWithTitle:[NSString stringWithUTF8String:gettext("Hide Others")] action:@selector(hideOtherApplications:) keyEquivalent:@"h"];
    [menuItem setKeyEquivalentModifierMask:(NSAlternateKeyMask|NSCommandKeyMask)];

    [appleMenu addItemWithTitle:[NSString stringWithUTF8String:gettext("Show All")] action:@selector(unhideAllApplications:) keyEquivalent:@""];

    [appleMenu addItem:[NSMenuItem separatorItem]];

    title = [NSString stringWithUTF8String:gettext("Quit Tux Paint")];
    [appleMenu addItemWithTitle:title action:@selector(terminate:) keyEquivalent:@"q"];


    /* Put menu into the menubar */
    menuItem = [[NSMenuItem alloc] initWithTitle:@"" action:nil keyEquivalent:@""];
    [menuItem setSubmenu:appleMenu];
    [[NSApp mainMenu] addItem:menuItem];

    /* Tell the application object that this is now the application menu */
    [NSApp setAppleMenu:appleMenu];

    /* Finally give up our references to the objects */
    [appleMenu release];
    [menuItem release];
}


static void setupWindowMenu(void)
{
    /*
    * Forked from SDLMain.m that comes with the SDL source code that comes with
    * MacPorts.  Credits to Darrell Walisser <dwaliss1@purdue.edu> and Max Horn
    * <max@quendi.de>.
    */

    NSMenu      *windowMenu;
    NSMenuItem  *windowMenuItem;
    NSMenuItem  *menuItem;

    windowMenu = [[NSMenu alloc] initWithTitle:[NSString stringWithUTF8String:gettext("Window")]];

    /* "Minimize" item */
    menuItem = [[NSMenuItem alloc] initWithTitle:[NSString stringWithUTF8String:gettext("Minimize")] action:@selector(performMiniaturize:) keyEquivalent:@"m"];
    [windowMenu addItem:menuItem];
    [menuItem release];

    /* Put menu into the menubar */
    windowMenuItem = [[NSMenuItem alloc] initWithTitle:[NSString stringWithUTF8String:gettext("Window")] action:nil keyEquivalent:@""];
    [windowMenuItem setSubmenu:windowMenu];
    [[NSApp mainMenu] addItem:windowMenuItem];

    /* Tell the application object that this is now the window menu */
    [NSApp setWindowsMenu:windowMenu];

    /* Finally give up our references to the objects */
    [windowMenu release];
    [windowMenuItem release];
}


static void removeSdlMenu(void)
{
    NSMenu* rootMenu = [NSApp mainMenu];

    /* SDL has two menus. Remove both. */

    [rootMenu removeItemAtIndex:0];
    [rootMenu removeItemAtIndex:0];
}


void apple_init(void)
{
    /* Override SDL's default menu with our gettext-translatable menu.  We do
     * this by adding our menus, then removing the menus installed by SDL. */
    setupApplicationMenu();
    setupWindowMenu();
    removeSdlMenu();
}
