## Version 1.12.3 (August 31st, 2017)
#### **Enhancements**
- Added a new Instabot user-response type - multi-select
- Added client-side support for conversations that contain a conversation path that connects to existing nodes in the conversation
- Added support for full, client-side Instabot-UI customization
- Added new start method to initialize the Instabot SDK in `didFinishLoadingWithOptions`

#### **Bug Fixes**
- Fixed issues related to incorrect conversation portal analytics from certain types of Instabot user-responses

## Version 1.12.2 (August 11th, 2017)
#### **Enhancements**
- Internal refactoring for upcoming new features and performance improvements

## Version 1.12.1 (July 14th, 2017)
#### **Enhancements**
- InstaBot text prompt nodes now support embedded YouTube videos 
- Any links detected (eg: www, http://, etc) in an InstaBot nodes are now directly clickable by the user within the InstaBot
- Added unique ID to each InstaBot conversation to allow for conversation tracking on a _session_ level in the Mobi portal
- Support added for the setting of Mobi custom properties within an InstaBot conversation for _anonymous_ users

#### **Bug Fixes**
- An engaged conversation session was being incorrectly listed as "no reply" instead of "engaged"
- Text keyboard appeared instead of the number keyboard when InstaBot asks for a phone number from the user
- Text keyboard appeared instead of an email-centric keyboard when InstaBot asks for a email from the user
- Duplicated InstaBot prompts in certain edge cases

## Version 1.12.0.0 (June 21, 2017)
#### **Enhancements**
- Updated InstaBot 2.0 UI
- More polished outlines for multiple choice options and images
- Standardized InstaBot icons to squares
- Beautified the layout for the description and selection text for rich media cards 
- Added grey borders around all images	
- Descriptions accompanying rich media images will be overlayed on top of image

#### **Bug Fixes**
- Fixed InstaBot multiple choice and attached images rendering on tablets and landscaped devices
- Fixed issue of the InstaBot launching for more times than configured in the Mobi portal
- Removed non-blocker error messages for when cacheFile is empty and dataToLoad is nil
- Fixed incorrect sticker pack appearing and crash when switching between apps
- Fixed poor UX when keyboard appears for free-text responses
- Fixed issue of improper phone-number property validation
- Fixed issue where external URL actions do not open when clicked
- Fixed issue of InstaBot conversations not scrolling all the way down under certain situations

## Version 1.10
- Meet Instabot 2.0!

## Version 1.9.8
- Instabot can be shown multiply times

## Version 1.9.7
- Bug fixed: Redeem referral discount workflow corrected

## Version 1.9.6
- Improvements of referral workflow

## Version 1.9.5
- New referral workflow

## Version 1.9.4
- Instabot. Long user answers support
- Improvements and stabilization of Instabot component
- Instabot. Conversations caching

## Version 1.9.3
- Bug fixed: unable to set custom property for user without avatar

## Version 1.9.2
- Auto prolonged server session

## Version 1.9.1
- Minor UI fixes in InstaBot

## Version 1.9.0
- New component: InstaBot

## Version 1.8.9
- Ability to change user custom properties

## Version 1.8.8
- Bug fixed: crash if user restricted access to contacts

## Version 1.8.7
- Bug fixed: Contact list is not loaded on very first try

## Version 1.8.6
- Modular framework. In Swift you may use import keyword instead of Objective-C bridge file
- Ability to get all promo codes user can use

## Version 1.8.5
- Bug fixed: Contacts list shows empty rows for contacts without first and last names

## Version 1.8.4
- Bug fixed: Sharing screen may crash when loads large images on slow connection
- Contacts picker now sorts contacts by display name

## Version 1.8.3
- Bug fixed: iOS 8.x. Closing cross icon is absent on promo in-app

## Version 1.8.1
- Support of CocoaPods 1.0
- Bug fixed: Invite Friends. Some contacts are absent
- Bug fixed: Crash on push notification with incorrect data.
- Improvement of deep links for iOS 8.4

## Version 1.8
- Updates in analytics
- Stability improvements in Deep Link component

## Version 1.5
- Debug messages in log. Use the following keys in run parameters: -ROKOAPIErrorsDebugEnabled, -ROKOAnalyticsDebugEnabled, -ROKODebugEnabled
- New error type for incorrect deep link
- Optimized images loading for ROKOShare screens

## Version 1.4
- New portal error handling
- New property in ROKOShare component: linkId
- Bug fixed: Sharing from Overlay does not work
- Bug fixed: Two deep links are shown when I share referral code via email right after I shared it via FB.

## Version 1.3
- _ROKO.Share.Shared event contains contentURL parameter now
- Bug fixed: HTML email looks bad if sharing text contains full HTML format and not empty portal greeting/signature
- Bug fixed: Events sending may be delayed in some cases

## Version 1.2
- ROKOLinkManager now supports links with parameters
- Share UI looks better with horizontal-oriented images
- Bug fixed: Invite friends. Search in contacts is case sensitive 

## Version 1.1
- Add some optimization and bug fixing

## Version 1.0.1
- Some stability improvements 

## Version 1.0.0
- Version 1.0.0 released!

## Version 0.5.3
- Refactoring of ROKOShare component

## Version 0.5.2
- Minor bugfixing

## Version 0.5.1
- Allows developer to block adding URL to sharing message for selected channel

## Version 0.5.0
- Allows user to share his referral code with friends from contacts

## Version 0.4.9
- Specify text for every share channel

## Version 0.4.8
- Allows user to share articles

## Version 0.4.7
- Deep links support

## Version 0.4.6
- Allows user to share his referral code

## Version 0.4.5
- ROKOReferral component
