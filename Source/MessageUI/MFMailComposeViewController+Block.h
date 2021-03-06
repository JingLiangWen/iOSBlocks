//
//  MFMailComposeViewController+Block.h
//  iOS Blocks
//
//  Created by Ignacio Romero Zurbuchen on 12/11/12.
//  Copyright (c) 2013 DZEN. All rights reserved.
//

#import <MessageUI/MessageUI.h>
#import "iOSBlocksProtocol.h"

__unused static NSString *kMFAttachmentData = @"MFMailAttachmentData";
__unused static NSString *kMFAttachmentMimeType = @"MFMailAttachmentMimeType";
__unused static NSString *kMFAttachmentFileName = @"MFMailAttachmentFileName";

/*
 * MessageUI MailComposeViewController Delegate block methods.
 */
@interface MFMailComposeViewController (Block) <MFMailComposeViewControllerDelegate, iOSBlocksProtocol>

/*
 * Prepares a MailComposeViewController to be presented with subject, message, recipients and attachment files, and with update blocks to notify when the user finishes by either sending or cancelling the mail.
 * If this is used on iPad, the MailComposeViewController will be presented modaly with presentation styled on UIModalPresentationFormSheet.
 *
 * @param subject The initial text for the subject line of the email.
 * @param message The initial body text to include in the email.
 * @param recipients The initial recipients to include in the email’s “To” field.
 * @param attachments An array of dictionnarys containing the specified data, MIME Type and file name to be attachmented to the message.
                      Use the kMFAttachmentData, kMFAttachmentMimeType and kMFAttachmentFileName to set the corresponding values.
 * @param creation A block object to be executed when the MailComposeViewController has been created and is ready to be presented. Returns the setup MailComposeViewController object.
 * @param finished A block object to be finished when the user wants to dismiss the mail composition view. Returns the setup MailComposeViewController object.
 */
+ (void)mailWithSubject:(NSString *)subject
                message:(NSString *)message
             recipients:(NSArray *)recipients
         andAttachments:(NSArray *)attachments
             onCreation:(ComposeCreatedBlock)creation
               onFinish:(ComposeFinishedBlock)finished;

/*
 * Prepares a MailComposeViewController to be presented with subject, message and recipients, and with update blocks to notify when the user finishes by either sending or cancelling the mail.
 * If this is used on iPad, the MailComposeViewController will be presented modaly with presentation styled on UIModalPresentationFormSheet.
 *
 * @param subject The initial text for the subject line of the email.
 * @param message The initial body text to include in the email.
 * @param recipients The initial recipients to include in the email’s “To” field.
 * @param creation A block object to be executed when the MailComposeViewController has been created and is ready to be presented. Returns the setup MailComposeViewController object.
 * @param finished A block object to be finished when the user wants to dismiss the mail composition view. Returns the setup MailComposeViewController object.
 */
+ (void)mailWithSubject:(NSString *)subject
                message:(NSString *)message
             recipients:(NSArray *)recipients
             onCreation:(ComposeCreatedBlock)creation
               onFinish:(ComposeFinishedBlock)finished;

@end
