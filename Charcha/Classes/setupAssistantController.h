//
//  setupAssistantController.h
//  Charcha
//
//  Created by Parthasarathi Susarla on 04/04/14.
//  Copyright (c) 2014 Parthasarathi Susarla. All rights reserved.
//

#import <Cocoa/Cocoa.h>

@interface setupAssistantController : NSWindowController

@property (nonatomic, weak) id delegate;

@property (nonatomic, weak) IBOutlet NSTextField *fullNameField;
@property (nonatomic, weak) IBOutlet NSTextField *ircNickField;
@property (nonatomic, weak) IBOutlet NSComboBox *ircServerField;
@property (nonatomic, weak) IBOutlet NSImageView *nameInvalidDataView;
@property (nonatomic, weak) IBOutlet NSImageView *nickInvalidDataView;
@property (nonatomic, weak) IBOutlet NSImageView *serverInvalidDataView;
@property (nonatomic, weak) IBOutlet NSButton *connectButton;
@property (nonatomic, weak) IBOutlet NSButton *skipButton;

- (void)show;
- (void)close;

@end

@interface NSObject (setupAssistantControllerDelegate)
- (void)setupAssistantController:(setupAssistantController*)sender onOK:(NSDictionary*)config;
- (void)setupAssistantControllerWillClose:(setupAssistantController*)sender;
@end
