//
//  SeafFile.h
//  seafile
//
//  Created by Wang Wei on 10/11/12.
//  Copyright (c) 2012 Seafile Ltd. All rights reserved.
//

#import <QuickLook/QuickLook.h>
#import "SeafConnection.h"
#import "SeafUploadFile.h"
#import "SeafBase.h"
#import "Utils.h"


@class SeafFile;

@protocol SeafFileUpdateDelegate <NSObject>
- (void)updateProgress:(SeafFile *)file result:(BOOL)res completeness:(int)percent;
@end

@interface SeafFile : SeafBase<QLPreviewItem, SeafPreView, SeafUploadDelegate, SeafDownloadDelegate>

- (id)initWithConnection:(SeafConnection *)aConnection
                     oid:(NSString *)anId
                  repoId:(NSString *)aRepoId
                    name:(NSString *)aName
                    path:(NSString *)aPath
                   mtime:(long long)mtime
                    size:(unsigned long long)size;

@property (strong, nonatomic) NSString *mpath;// For modified files
@property (readonly) NSString *detailText;
@property (readwrite) long long filesize;
@property (readwrite) long long mtime;
@property (readonly) NSMutableArray *groups;
@property (strong) id <SeafFileUpdateDelegate> udelegate;

- (BOOL)isStarred;
- (void)setStarred:(BOOL)starred;
- (void)deleteCache;
- (void)update:(id<SeafFileUpdateDelegate>)dg;
- (void)cancelDownload;


- (BOOL)testupload;

@end
