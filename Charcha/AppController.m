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
#import "setupAssistantController.h"

#import <Growl/Growl.h>

@interface AppController () <NSUserNotificationCenterDelegate, GrowlApplicationBridgeDelegate>

@end

@implementation AppController

setupAssistantController *_setupAssistanController;


#pragma mark - NSOBject Delegate
+ (void)initialize
{
    printf("initalize\n");
}

- (id)init
{
    printf("init\n");
    self = [super init];
    if (self == nil) {
        return nil;
    }
    
    return self;
}

- (void)dealloc
{
    printf("dealloc\n");
}

#pragma -
#pragma mark NSApplication delegate
- (void)awakeFromNib
{
    NSWindowCollectionBehavior behavior = [_mainWindow collectionBehavior];
    behavior |= NSWindowCollectionBehaviorFullScreenPrimary;
    [_mainWindow setCollectionBehavior:behavior];

    printf("awakefromnib\n");
}

- (void)applicationDidFinishLaunching:(NSNotification *)aNotification
{
    printf("applicationdidfinishlaunching\n");
    
    if (1) {
        printf("showing setupAssistantController\n");
        _setupAssistanController = [setupAssistantController new];
        _setupAssistanController.delegate = self;
        [_setupAssistanController show];
    } else {
        printf("launching the application\n");
        [_mainWindow makeKeyAndOrderFront:nil];
    }
}

- (NSApplicationTerminateReply)applicationShouldTerminate:(NSApplication *)sender
{
    printf("applicationshould terminate\n");
    return NSTerminateNow;
}

- (void)applicationWillTerminate:(NSNotification *)aNotification
{
    printf("application will terminate\n");
}
#pragma -
@end
