# Roko Mobi iOS

[![Platform](https://img.shields.io/cocoapods/p/ROKOComponents.svg?style=flat)](http://cocoapods.org/pods/ROKO.Mobi)

*This is a repository of all ROKO Mobi open source iOS SDKs. The information below should serve as a usage guide for our iOS SDKs. See the table of contents below for a complete list of the content featured in this document.*

|Table of Contents|
-------------------
|[Get Our Demo Apps][demoapps]|
|[Roko Stickers][stickers]|
|[Roko Share][share]|

[demoapps]: #get-our-demo-apps
[stickers]: #rokostickers-usage-guide
[share]: #rokoshare-usage-guide

##Get our Demo Apps 

ROKO has showcased many of our components in Demo Apps on the App Store. Check out our demo, [ROKO Stickers](https://itunes.apple.com/sb/app/roko-stickers/id980258381?mt=8), which includes the Stickers and Share SDKs, on the Apple App store.

## ROKOStickers Usage Guide

The ROKOStickers framework provides a means for taking photos, dressing them up in stickers, and sharing the results with the world through FB, Twitter, e-mail, or sms.

### Prerequisites

1) ROKOStickers framework requires iOS 7.0 or later.

2) Install Xcode 6.0 or later.

###Configure your Xcode Project

There are two ways to configure Xcode project: manual and via Cocoapods.

#### Cocoapods
Add the following line to your pod file:
```
pod "ROKO.Mobi"
```
and run 
```
$ pod install
````
in your project directory

#### Manual

1) Drag and drop Framework files:

```
ROKOMobi.framework

ROKOMobiResources.bundle
```

into your Xcode project (select "Create groups for any added folders" if needed). These packages contain the static libraries, header files, and necessary resources (configuration files and images).

---

2) Check the following frameworks within the "Link Binary With Libraries" build phase of your project’s target: 

```
ROKOMobi.framework 
Social.framework 
MessageUI.framework
AVFoundation.framework 
ImageIO.framework
CoreGraphics.framework 
QuartzCore.framework
UIKit.framework 
Foundation.framework
```

---

3) Make sure ROKOStickers.bundle and ROKOShare.bundle are included in your target's "Copy Bundle Resources" build phase.

---

4) Include the following line to make the Framework available to your code:

```
#import <ROKOMobi/ROKOMobi.h>
```

---

###Creating photos with ROKOStickers

![](Images/stickers_complete_workflow.png)

Figure #1. ROKOStickers WORKFLOW

The code examples in this page demonstrate how to fine-tune and display the photo composer, as well as customize it with your own branded sticker packs.
Integrating ROKOStickers you may choose among several starting points:

####1) Display the View Controller

* User can take a new photo by invoking the camera
* Or user can get images from their camera roll using the Image Picker

On your view add two buttons (call it takePhotoButton and choosePhotoButton). Then connect them with apporopriate functions in your viewcontroller. And set self as datasource delegate if using local stickers (or another datasource if using internet stickers - this example descibes later). 

Use kRLComposerWorkflowTypeCamera - to start with Screen 1a. Camera View (Figure #1).

```Objective-C
- (IBAction)takePhotoButtonPressed:(UIButton *)sender {
	RLComposerWorkflowController *workflowController = [RLComposerWorkflowController buildComposerWorkflowWithType:kRLComposerWorkflowTypeCamera useROKOCMS:NO];

	if (nil != workflowController) {
		workflowController.composer.dataSource = self;
		workflowController.composer.delegate = self;
		[self presentViewController:workflowController animated:YES completion:nil];
	}
}
```

Use kRLComposerWorkflowTypePhotoPicker - to start with Screen 1b. Image Picker (Figure #1)

```Objective-C
- (IBAction)choosePhotoButtonPressed:(UIButton *)sender {
	RLComposerWorkflowController *workflowController = [RLComposerWorkflowController buildComposerWorkflowWithType:kRLComposerWorkflowTypePhotoPicker useROKOCMS:NO];

	if (nil != workflowController) {
		RLPhotoComposerController *photoComposer = workflowController.composer;
		photoComposer.delegate = self;
		photoComposer.dataSource = self;

		[self presentViewController:workflowController animated:YES completion:nil];
	}
}
```

####2) Configure ROKOStickers' behavior & content:


You may chose to register your project on ROKO Mobi Portal, which provides easy-to-use GUI, or to configure the ROKOStickers framework and manage it’s content. If you do so, you may skip the following section. Alternatively you may chose to manage the ROKOStickers independently, in this case the following section is a guide for you.

#####a) Customize Composer View appearance.

Add instance variable at you viewcontroller

```Objective-C
@interface ViewController () {
	ROKOStickersScheme *_scheme;
}

```

Customize your own vision of appearance

```Objective-C
- (void)viewDidLoad {
	[super viewDidLoad];
	_scheme = [self createScheme];
}

- (ROKOStickersScheme *)createScheme {
	ROKONavigationBarScheme *naviScheme = [ROKONavigationBarScheme new];
	naviScheme.controllerTitle = @"Stickers";
	naviScheme.useTextButtons = YES;
	naviScheme.navigationLeftButtonText = @"back";
	naviScheme.navigationRightButtonText = @"next";
	naviScheme.navigationBarColor = [UIColor whiteColor];

	ROKOStickersTrayScheme *trayScheme = [ROKOStickersTrayScheme new];
	trayScheme.displayType = ROKOStickersTrayDisplayTypeIconOnly;
	trayScheme.backgroundColor = [[UIColor alloc] initWithWhite:1 alpha:0.5];

	ROKOStickersScheme *scheme = [ROKOStickersScheme new];
	scheme.configurationViaPortal = NO;
    scheme.albumName = @"ROKO Strik";
	scheme.navigationBarScheme = naviScheme;
	scheme.trayScheme = trayScheme;
	return scheme;
}
```

Apply your scheme at willAppear callback - 

```Objective-C
- (void)composer:(RLPhotoComposerController *)composer willAppearAnimated:(BOOL)animated {
	if (_scheme) {
		composer.scheme = _scheme;
	}
}
```

#####b) provide sticker packs content from local resources:

Create sticker packs for local resources. Make sure you add Resource directory to your project. Start with declaration of stickers collection add 2 ivars: 

```Objective-C
@interface ViewController () {
	NSArray *_stickerPacks;
	NSDictionary *_stickerPackToIconsCount;
}
```

Fill content to stickers collection

```Objective-C
- (void)viewDidLoad {
	[super viewDidLoad];

	_stickerPackToIconsCount = @{ @"glasses" : @10, @"hats" : @9, @"mustaches" : @9, @"baby" : @22,
		                         @"cake" : @9, @"cat" : @12, @"emoji" : @18, @"wedding" : @12 };

	NSMutableArray *mutableArray = [[NSMutableArray alloc] initWithCapacity:_stickerPackToIconsCount.allKeys.count];
	for (NSString *key in _stickerPackToIconsCount.allKeys) {
		[mutableArray addObject:[self getStickerPack:key]];
	}
	_stickerPacks = [mutableArray copy];
}

- (RLStickerPackInfo *)getStickerPack:(NSString *)packName {
	RLStickerPackInfo *packInfo = [RLStickerPackInfo new];
	packInfo.title = packName;
	packInfo.iconDefault = [UIImage imageNamed:[NSString stringWithFormat:@"%@_icon_default", packName]];
	packInfo.iconSelected = [UIImage imageNamed:[NSString stringWithFormat:@"%@_icon_selected", packName]];
	packInfo.isLocked = NO;

	NSNumber *iconsCount = [_stickerPackToIconsCount objectForKey:packName];
	if (iconsCount) {
		NSInteger count = [iconsCount integerValue];
		NSMutableArray *mutableArray = [[NSMutableArray alloc] initWithCapacity:count];
		for (NSInteger i = 0; i < count; ++i) {
			RLStickerInfo *info = [self stickerInfoWithIndex:i packName:packName];
			[mutableArray addObject:info];
		}
		packInfo.stickers = [mutableArray copy];
	}
	return packInfo;
}
```

Implement RLPhotoComposerDataSource protocol in your viewcontroller. Start with interface.

```Objective-C
@interface ViewController : UIViewController <RLPhotoComposerDataSource>
@end
```

Set *self* as a "dataSource" of the "composer" property of RLComposerWorkflowController.

```Objective-C
RLPhotoComposerController *photoComposer = workflowController.composer;
photoComposer.dataSource = self;
```

Then implement data source methods.

```Objective-C
- (NSInteger)numberOfStickerPacksInComposer:(RLPhotoComposerController *)composer {
	return [_stickerPacks count];
}
// return the number of sticker packs to display on Stickers Selector (Figure #1)


- (NSInteger)numberOfStickersInPackAtIndex:(NSInteger)packIndex composer:(RLPhotoComposerController *)composer {
	RLStickerPackInfo *pack = _stickerPacks[packIndex];
	return [pack.stickers count];
}
// return the number of stickers per each packs

- (RLStickerPackInfo *)composer:(RLPhotoComposerController *)composer infoForStickerPackAtIndex:(NSInteger)packIndex {
	return _stickerPacks[packIndex];
}
// return info for each sticker pack

- (RLStickerInfo *)composer:(RLPhotoComposerController *)composer infoForStickerAtIndex:(NSInteger)stickerIndex packIndex:(NSInteger)packIndex {
	RLStickerPackInfo *pack = _stickerPacks[packIndex];
	RLStickerInfo *info = pack.stickers[stickerIndex];
	return info;
}
// return info for each sticker
```

#####c) Provide sticker packs content from ROKO Portal:

Start with creation two strings on yout .plist.

|Key|Value|
---|---
|ROKOMobiAPIURL|rmsws.stage.rokolabs.com/external/v1|
|ROKOMobiAPIToken|[%YOUR_API_FROM_SERVER%](https://portal.roko.mobi/settings)|

Declare and initialize instance variable dataSource :

```Objective-C
@interface ViewController () {
	ROKOPortalStickersDataSource *_dataSource;
}

- (void)viewDidLoad {
_dataSource = [[ROKOPortalStickersDataSource alloc]init];
    	_scheme = [self createScheme];
}
```

Set composer datasource and refresh stickers list. 

```Objective-C
- (IBAction)choosePhotoButtonPressed:(UIButton *)sender {
	RLComposerWorkflowController *workflowController = [RLComposerWorkflowController buildComposerWorkflowWithType:kRLComposerWorkflowTypePhotoPicker useROKOCMS:NO];

    if (nil != workflowController) {
        workflowController.composer.dataSource = _dataSource;
        [self loadStickersForController:workflowController];
        workflowController.composer.delegate = self;
        [self presentViewController:workflowController animated:YES completion:nil];
    }
}

- (void)loadStickersForController:(RLComposerWorkflowController *)controller {
    __weak RLPhotoComposerController *composer = controller.composer;
    [_dataSource reloadStickersWithCompletionBlock:^(id responseObject, NSError *error) {
        [composer reloadData];
    }];
}
```

#####d) Provide watermark to display on photo

User can add watermark to image when user starts using some sticker pack, for example for “wedding” sticker pack. After filling sticker collection add this code:

```Objective-C
- (void)addWatermarkToWeddingStickerPack {
	for (RLStickerPackInfo *stickerPack in _stickerPacks) {
		if ([stickerPack.title isEqualToString:@"wedding"]) {
			RLWatermarkInfo *info = [RLWatermarkInfo new];
			info.icon = [UIImage imageNamed:@"watermark_3"];
			info.position = kRLWatermarkPositionBottomRight;
			stickerPack.watermarkInfo = info;
		}
	}
}
```

It’s automatically add watermark when using at least one sticker form “wedding” pack.

Even user can add watermark to whole image using composer

```Objective-C
RLWatermarkInfo *watermark = [RLWatermarkInfo new];
watermark.icon = [UIImage imageNamed:@"watermark_3"];
watermark.position = kRLWatermarkPositionBottomRight;

RLPhotoComposerController *photoComposer = workflowController.composer;
photoComposer.dataSource = self;
photoComposer.projectWatermark = watermark;
```

Note:

1) you may choose among a variety of options to place the watermark on screen:

```
kRLWatermarkPositionTopLeft, 
kRLWatermarkPositionTop, 
kRLWatermarkPositionTopRight, 
kRLWatermarkPositionLeft, 
kRLWatermarkPositionCenter, 
kRLWatermarkPositionRight, 
kRLWatermarkPositionBottomLeft, 
kRLWatermarkPositionBottom, 
kRLWatermarkPositionBottomRight 
kRLWatermarkPositionFullScreen 
```

2) you may provide scale factor for the watermark from 0.1 to 1. Default is 1.

#####e) Further customization:

Display sticker packs as:

```
ROKOStickersTrayDisplayTypeIconOnly,
ROKOStickersTrayDisplayTypeTitleOnly,
ROKOStickersTrayDisplayTypeTitleAndIcon
```

![](Images/display_sticker_packs_as.png)

Use

```Objective-C
ROKOStickersTrayScheme *trayScheme = [ROKOStickersTrayScheme new];
	trayScheme.displayType = ROKOStickersTrayDisplayTypeIconOnly;
```

##ROKOShare Usage Guide

###Before You Begin:

1) ROKOMobi framework requires iOS 7.0 or later.

2) Install Xcode 6.0 or later.

3) ROKOShare framework supports both iPhone and iPad user interface.

###Configure Your Xcode Project:

####1) Add Files

Copy the ROKOMobi.framework and ROKOMobiResources.bundle into your project (select "Create groups for any added folders" if needed). These packages contain the static library, header files, and necessary resources (configuration files and images).

####2) Add the following frameworks within the "Link Binary With Libraries" build phase of your project’s target:

```
ROKOMobi.framework
Social.framework
MessageUI.framework
ImageIO.framework
CoreLocation.framework
QuartzCore.framework
UIKit.framework
Foundation.framework
```

####3) Make sure ROKOShare.bundle is included in your target's "Copy Bundle Resources" build phase.

####4) Generate the API Token by registering your project on ROKO Mobi Portal. Add «ROKOMobiAPIToken» key to your Xcode project’s info.plist and set the generated API Token as it’s value

picture

####5) Include the following line to make the Framework available to your code:

```Objective-C
#import <ROKOMobi/ROKOMobi.h>
```

###Sharing Content with ROKOShare

The ROKOShare framework provides a means to share rich content from your app into the sms, e-mail, Twitter, and Facebook, including text, photos, and URL attachments. The code examples in this page demonstrate how to customize and display the sharing dialog, as well be informed about posting results within your app.

####1) Display the View Controller

To integrate ROKOShare in your application, create an instance of RSActivityViewController and present in on screen:

```Objective-C
- (void)showROKOShare{
RSActivityViewController *controller = [RSActivityViewController buildController]; self.modalPresentationStyle = UIModalPresentationCurrentContext; [self presentViewController:controller                   animated:YES                 completion:^{    self.modalPresentationStyle = UIModalPresentationFullScreen;
}];
}
```

Note: UIModalPresentationCurrentContext must be applied to your window’s rootViewController, i.e. if your view controller is embedded into UINavigationController, then UIModalPresentationCurrentContext must be applied to UINavigationController:

```Objective-C
  self.navigationController.modalPresentationStyle = UIModalPresentationCurrentContext;
```

####2) Provide the subject, message, image, and/or URL to be shared:

```Objective-C
- (void)showROKOShare
{
RSActivityViewController *controller = [RSActivityViewController buildController]; NSString *subject = @"New Post"; [controller addSubject:subject]; NSString *displayMessage = @"This message will be displayed in message view"; [controller addDisplayMessage:displayMessage]; NSString *shareMessage = @"This message will be shared";
[controller addShareMessage:shareMessage]; UIImage *image = [UIImage imageNamed:@"myImage.png"]; [controller addImage:image]; NSURL *url = [NSURL URLWithString:@"http://www.rokolabs.com/"]; [controller addURL:url]; 
}
```
Note: ROKOShare framework offers the option of using two different messages: 

- display message: to be displayed in the view controller’s «Message View» (please refer to the image in «Customize ROKOShare appearance» section), set via addDisplayMessage:

- share message: to be actually shared via social services, set via addShareMessage:.

This option will only work if the «Message View» is not be editable (which is default).
Please follow «Customizing ROKOShare appearance» section to get to know how to make the MessageView editable. 

####3) Detect that the post was shared successfully from your app

a) Declare that your view controller implements the RSActivityViewControllerDelegate protocol:

```Objective-C
@interface MyViewController : UIViewController <RSActivityViewControllerDelegate> 
```

b) Before you present the instance of RSActivityViewController, set your

```Objective-C
RSActivityViewController’s delegate:
controller.delegate = self;
```

c) Implement delegate’s methods:

```Objective-C
- (void)activityControllerDidCancel:(RSActivityViewController *)controller
{    NSLog(@"CANCEL BUTTON PRESSED");
}
- (void)activityController:(RSActivityViewController *)controller didFinishWithActivityType:(RSActivityType)activityType result: (RSActivityViewControllerResult)result {    switch (result) {        case kRSActivityViewControllerResultCancelled:            NSLog(@"SHARING CANCELLED");            break;        case kRSActivityViewControllerResultFailed:            NSLog(@"SHARING FAILED");            break;        case kRSActivityViewControllerResultDone:            NSLog(@"SHARED SUCCESSFULLY");            break;        default:
break; 
}
}
```

###Customizing ROKOShare Appearance:
