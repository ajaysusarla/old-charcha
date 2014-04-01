//
//  AppController.h
//  Charcha
//
//  Created by Parthasarathi Susarla on 01/04/14.
//  Copyright (c) 2014 Parthasarathi Susarla. All rights reserved.
//

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
