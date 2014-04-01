//
//  CharchaAppDelegate.h
//  Charcha
//
//  Created by Parthasarathi Susarla on 01/04/14.
//  Copyright (c) 2014 Parthasarathi Susarla. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface CharchaAppDelegate : NSObject <NSApplicationDelegate>

@property (assign) IBOutlet NSWindow *window;

@property (readonly, strong, nonatomic) NSPersistentStoreCoordinator *persistentStoreCoordinator;
@property (readonly, strong, nonatomic) NSManagedObjectModel *managedObjectModel;
@property (readonly, strong, nonatomic) NSManagedObjectContext *managedObjectContext;

- (IBAction)saveAction:(id)sender;

@end
