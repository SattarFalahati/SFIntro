# SFIntro
Intro / Tutorial 

iOS Version 9+

## How it's Work
To implement and make this framework working : Copy SFIntro.h/m and SFIntroView.xib to your project.

You can change everything in this class and also you can setUp your own desire colors and fonts.

## Delegate 
You can Use delegates to controll the intro.

Use this to handle SFIntroView objects at desire index (this delegate will called on SFIntro initialization)
```
-(void)presentedIntroViewPage:(SFIntroView *)page atIndex:(NSInteger)pageIndex withSFIntroObject:(NSDictionary *)dicSFIntroObject;
```

Use this to handle SFIntro objects at desire index (this delegate will called on presenting each single page)
```
-(void)presentedIntroPage:(SFIntro *)intro atIndex:(NSUInteger)pageIndex;
```
Handle first button 
```
-(void)firstButtonDidSelectWithIntro:(SFIntro *)intro;
```

Handle second button
```
-(void)secondButtonDidSelectWithIntro:(SFIntro *)intro;
```
## Versioning

Version 1.0.1

## Author
Sattar Falahati 

iOS Developer

Plase report any bug you find
 
sattar.falahati@gmail.com

## License

This project is licensed under the MIT License
