//
//  ViewController.m
//  SFIntroExample
//
//  Created by Sattar Falahati on 29/03/17.
//  Copyright © 2017 Sattar Falahati. All rights reserved.
//

#import "ViewController.h"

#import "SFIntro.h"

@interface ViewController () <SFIntroDelegate>

@property (strong, nonatomic) SFIntro *intro;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
}

- (IBAction)openSFIntro:(id)sender
{
    [self initSFIntro];
}


// Initial SFIntro

- (void)initSFIntro
{
    // Create SFIntroObjects
    NSArray *arr = @[@{kSFIntroObjectImage : @"trolltunga",
                       kSFIntroObjectTitle : @"Trolltunga is amazing",
                       kSFIntroObjectDescription : @"“I took a deep breath and listened to the old brag of my heart; I am, I am, I am.” \n Sylvia Plath, The Bell Jar",
                       },
                     @{kSFIntroObjectImage : @"colorFullLife",
                       kSFIntroObjectTitle : @"Color Full Life",
                       kSFIntroObjectDescription : @"“Failure is simply the opportunity to begin again, this time more intelligently.”\n Henry Ford",
                       },
                     @{kSFIntroObjectImage : @"Placeholder",
                       kSFIntroObjectTitle : @"title for third page",
                       kSFIntroObjectDescription : @"This is a description for third page",
                       }];
    
    // Initial 
    self.intro = [SFIntro initWithFrame:self.view.frame withParallaxBackgroundImage:@"BG" withDelegate:self withDataSourceArray:arr];
    
    // Change UI of SFIntro here (Uncoment the coments)
//    [self.intro.btnFirst setTitleColor:[UIColor redColor] forState:UIControlStateNormal];
//    [self.intro.btnSecond setBackgroundColor:[UIColor yellowColor]];
    
    // Prepare for animation
    self.intro.alpha = 0;
    [self.view addSubview:self.intro];
    
    // Open the page
    [UIView animateWithDuration:0.7f animations:^{
        self.intro.alpha = 1;
    } completion:^(BOOL finished) {
    }];
}

// MARK: - Delagate

- (void)firstButtonDidSelectWithIntro:(SFIntro *)intro
{
    // Close the page
    [UIView animateWithDuration:0.7f animations:^{
        self.intro.alpha = 0;
    } completion:^(BOOL finished) {
        [self.intro removeFromSuperview];
    }];
}

- (void)secondButtonDidSelectWithIntro:(SFIntro *)intro
{
    [self.intro goToPageAtIndex:1];
}

- (void)presentedIntroViewPage:(SFIntroView *)page atIndex:(NSInteger)pageIndex withSFIntroObject:(NSDictionary *)dicSFIntroObject
{
    NSLog(@"%lu", (unsigned long)pageIndex);
    
    if (pageIndex == 2) {
        [page.lblTitle setText:@"Changed title"];
    }
}

- (void)presentedIntroPage:(SFIntro *)intro atIndex:(NSUInteger)pageIndex
{
    if (pageIndex+1 == intro.arrContent.count) {
        [intro showButtons];
    }
    else {
        [intro hideButtons];
    }
}



@end
