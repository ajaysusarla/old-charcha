/*
 * AppController.h
 *
 * Charcha
 * Copyright (c) 2014 Parthasarathi Susarla. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this program. If not, see <http://www.gnu.org/licenses/>.
 *
 */

#import <Foundation/Foundation.h>

@interface AppController : NSObject

// Window Menu
@property (nonatomic, weak) IBOutlet NSMenu *windowMenu;

// Preferences Menu Item
@property (nonatomic, weak) IBOutlet NSMenuItem *preferencesMenuItem;

-(IBAction)showPreferencesWindow:(id)sender;      // Show preferences Window
-(IBAction)setupOnFirstLaunch:(id)sender;         // Setup basic account stuff on first launch
-(void)startUserAttentionTimer;                   // Starts the timer for bouncing icon on the dock
-(void)stopUserAttentionTimer;                    // Stops the time for bounching icon on the dock
-(void)requestUserAttentionTick:(NSTimer *)timer; // method to call when a userattentiontimer fires
-(void)updateDockTileBadgeLabel;                  // Updates the dock tile badge label

@end
