//
//  SFIntro.h
//  Reevelo
//
//  Created by Sattar Falahati on 28/03/17.
//  Copyright © 2017 App to you. All rights reserved.
//

#import <UIKit/UIKit.h>

// MARK: - SFIntro

/**
 * SFIntro 
 * To implement and make this class working : Copy SFIntro.h/m and SFIntroView.xib to your project
 * You can change everything in this class and also you can settUp your on desire colors anf fonts.
 * SFIntro is a view which contains
 * Parallax scroll view : to show an image with parallax in backgreound of the intro
 * Scroll view : to hold SFIntroViews
 * Buttons : for controlling two actions on view
 * Pager : to show pages 
 *
 * SFIntroView
 * SFIntroView is a view inisde SFIntro which contains
 * UIImageView : uiimage view to hold an image
 * lblTitle : intro title
 * lblDescription : intro description
 *
 * SFIntro works from ios 8+
 * SFIntroObject = User snd an array of SFIntroObjects then SFIntro will generate pages based on received objects 
 */

// Lets present delegate to SFIntro
@protocol SFIntroDelegate;

// Keys for SFIntroView objects
static NSString *const kSFIntroObjectImage = @"imageName"; // Use it for image
static NSString *const kSFIntroObjectTitle = @"title"; // Use it for title
static NSString *const kSFIntroObjectDescription = @"description"; // Use it for description

@interface SFIntro : UIView

// Delegate
@property (strong, nonatomic) id<SFIntroDelegate> delegate;

/**
 * Initial SFIntro
 * frame = to hold view size
 * strParallaxBGImage = an image for parallax background (if user send it nil it background won't be parallax)
 * delegate
 * arrDataSource = SFIntroObjects (image, title, description)
 * SFIntro
 */
+ (instancetype)initWithFrame:(CGRect)frame withParallaxBackgroundImage:(NSString *)strParallaxBGImage withDelegate:(id<SFIntroDelegate>) delegate withDataSourceArray:(NSArray *)arrDataSource;

/// Use this to scroll in desire page
- (void)goToPageAtIndex:(NSUInteger)page;

/// Hide and show buttons
- (void)hideFirstButton;
- (void)hideSecondButton;
- (void)hideButtons;
- (void)showFirstButton;
- (void)showSecondButton;
- (void)showButtons;

/// Array of sf intro objects
@property (strong, nonatomic) NSArray <NSDictionary*> *arrContent;

/// Presented page index
@property (nonatomic) NSInteger presentedPageIndex;;


// UI
@property (weak, nonatomic) IBOutlet UIScrollView *scrollView;
@property (strong, nonatomic) IBOutlet UIPageControl *pager;
@property (weak, nonatomic) IBOutlet UIStackView *buttons;
@property (strong, nonatomic) IBOutlet UIButton *btnFirst;
@property (strong, nonatomic) IBOutlet UIButton *btnSecond;
@property (weak, nonatomic) IBOutlet UIScrollView *parallaxScrollView;

@end

// MARK: - SFIntroView

@interface SFIntroView : UIView

// UI
@property (weak, nonatomic) IBOutlet UIImageView *img;
@property (weak, nonatomic) IBOutlet UILabel *lblTitle;
@property (weak, nonatomic) IBOutlet UILabel *lblDescription;

@end

// MARK: - Delegate

@protocol SFIntroDelegate <NSObject>

/// Handle firt button
-(void)firstButtonDidSelectWithIntro:(SFIntro *)intro;

/// Handle second button
-(void)secondButtonDidSelectWithIntro:(SFIntro *)intro;

/**
 * Use this to handle SFIntroView objects at desire index (this delegate will called on SFIntro initialization)
 * pageIndex
 * page (SFIntroView) which contains image, title, description
 * dicSFIntroObject which contains all objects image, title, description
 */
-(void)presentedIntroViewPage:(SFIntroView *)page atIndex:(NSInteger)pageIndex withSFIntroObject:(NSDictionary *)dicSFIntroObject;

/**
 * Use this to handle SFIntro objects at desire index (this delegate will called on presenting each single page)
 * intro
 * pageIndex
 * you can change buttons / grafic or ... on onle one desire page or you van have diffrent setup for each single page.
 */
-(void)presentedIntroPage:(SFIntro *)intro atIndex:(NSUInteger)pageIndex;

@end
