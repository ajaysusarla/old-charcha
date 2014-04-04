//
//  setupAssistantController.m
//  Charcha
//
//  Created by Parthasarathi Susarla on 04/04/14.
//  Copyright (c) 2014 Parthasarathi Susarla. All rights reserved.
//

#import "setupAssistantController.h"

@interface setupAssistantController ()

@end

@implementation setupAssistantController

- (id)init
{
    self = [super init];
    if (self) {
        [[NSBundle mainBundle] loadNibNamed:@"setupAssistantController"
                                      owner:self
                            topLevelObjects:nil];
    }
    return self;
}

- (void)windowDidLoad
{
    [super windowDidLoad];
    
    // Implement this method to handle any initialization after your window controller's window has been loaded from its nib file.
}

- (void)show
{
    printf("setupAssistantController: show\n");
    if (![self.window isVisible]) {
        [self.window center];
        printf("setupAssistantController: should show\n");
    }
    
    [self.window makeKeyAndOrderFront:nil];
}

- (void)close
{
    _delegate = nil;
    [self.window close];
}


@end
