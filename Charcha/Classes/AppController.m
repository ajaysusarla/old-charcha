/*
 * AppController.m
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


#import "AppController.h"

#import <Growl/Growl.h>

// Bouncing icon in the dock time interval
static const NSTimeInterval _userAttentionRequestInterval = 8.0;

@interface AppController () <NSUserNotificationCenterDelegate, GrowlApplicationBridgeDelegate>

@end

@implementation AppController

+ (void)initialize
{
    static BOOL initialized = NO;
    
    printf("initialize\n");
    
    if (!initialized) {
        
        initialized = YES;
    }
}

- (id)init
{
    self = [super init];
    if (self == nil) {
        return nil;
    }
    printf("init\n");
    NSNotificationCenter *notificationCenter = [NSNotificationCenter defaultCenter];
    
    // Subscribe to NSWorkspace notifications:
    //          * going to sleep
    //          * waking up from sleep
    //          * switching user session
    notificationCenter = [[NSWorkspace sharedWorkspace] notificationCenter];
    [notificationCenter addObserver:self
                           selector:@selector(workspaceWillSleep:)
                               name:NSWorkspaceWillSleepNotification
                             object:nil];
    [notificationCenter addObserver:self
                           selector:@selector(workspaceDidWake:)
                               name:NSWorkspaceDidWakeNotification
                             object:nil];
    [notificationCenter addObserver:self
                           selector:@selector(workspaceSessionDidResignActive:)
                               name:NSWorkspaceSessionDidResignActiveNotification
                             object:nil];
    [notificationCenter addObserver:self
                           selector:@selector(workspaceSessionDidBecomeActive:)
                               name:NSWorkspaceSessionDidBecomeActiveNotification
                             object:nil];

    
    return self;
}

- (void)dealloc
{
    [[NSNotificationCenter defaultCenter] removeObserver:self];
    [[[NSWorkspace sharedWorkspace] notificationCenter] removeObserver:self];
}


-(IBAction)showPreferencesWindow:(id)sender
{
}

-(IBAction)setupOnFirstLaunch:(id)sender
{
    
}

-(void)startUserAttentionTimer
{
    
}

-(void)stopUserAttentionTimer
{
    
}

-(void)requestUserAttentionTick:(NSTimer *)timer
{
    
}

-(void)updateDockTileBadgeLabel
{
    
}


#pragma mark -
#pragma mark NSWorkspace notifications

// Disconnect all IRC connections before going to sleep
- (void)workspaceWillSleep:(NSNotification *)notification
{
   
}

- (void)workspaceDidWake:(NSNotification *)notification
{

}

- (void)workspaceSessionDidResignActive:(NSNotification *)notification
{

}

- (void)workspaceSessionDidBecomeActive:(NSNotification *)notification
{

}

#pragma mark -
#pragma mark NSWindow notifications
- (void)windowWillClose:(NSNotification *)notification
{
}

#pragma mark -
#pragma mark NSApplication delegate methods
- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    // Application control will start from here
    printf("application did finish launch\n");
}

// Reopen all Charcha windows when dock icon is clicked
- (BOOL)applicationShouldHandleReopen:(NSApplication *)theApplication hasVisibleWindows:(BOOL)flag
{
    return YES;
}

- (void)applicationDidBecomeActive:(NSNotification *)aNotification
{
    printf("Application did become active\n");
}

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender
{
    printf("Terminating Application\n");
    return NSTerminateNow;
}
@end
