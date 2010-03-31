/*
 Copyright (c) 2009, Stefan Reitshamer http://www.haystacksoftware.com
 
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are met:
 
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 
 * Redistributions in binary form must reproduce the above copyright
 notice, this list of conditions and the following disclaimer in the
 documentation and/or other materials provided with the distribution.
 
 * Neither the names of PhotoMinds LLC or Haystack Software, nor the names of 
 their contributors may be used to endorse or promote products derived from
 this software without specific prior written permission.
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED
 TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
 PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
 LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
 NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */ 

#import <Cocoa/Cocoa.h>
#import "Blob.h"
#import "BufferedInputStream.h"
#import "OutputStream.h"
@class Node;
@class MutableS3Repo;

#define CURRENT_TREE_VERSION 10

@interface Tree : NSObject {
    int treeVersion;
	NSString *xattrsSHA1;
    unsigned long long xattrsSize;
	NSString *aclSHA1;
    int uid;
    int gid;
	int mode;
	long long mtime_sec;
	long long mtime_nsec;
	long long flags;
	int finderFlags;
	int extendedFinderFlags;
    int st_dev;
    int st_ino;
    uint32_t st_nlink; // in struct stat, it's only 16 bits.
    int st_rdev;
    int64_t ctime_sec;
    int64_t ctime_nsec;
    int64_t createTime_sec;
    int64_t createTime_nsec;
    int64_t st_blocks;
    uint32_t st_blksize;
	NSMutableDictionary *nodes;
}
- (id)init;
- (id)initWithBufferedInputStream:(id <BufferedInputStream>)is error:(NSError **)error;
- (NSArray *)childNodeNames;
- (Node *)childNodeWithName:(NSString *)name;
- (BOOL)containsNodeNamed:(NSString *)name;

@property(readonly,copy) NSString *xattrsSHA1;
@property(readonly) unsigned long long xattrsSize;
@property(readonly,copy) NSString *aclSHA1;
@property(readonly) int uid;
@property(readonly) int gid;
@property(readonly) int mode;
@property(readonly) long long mtime_sec;
@property(readonly) long long mtime_nsec;
@property(readonly) long long flags;
@property(readonly) int finderFlags;
@property(readonly) int extendedFinderFlags;
@property(readonly) int treeVersion;
@property(readonly) int st_rdev;
@property(readonly) long long ctime_sec;
@property(readonly) long long ctime_nsec;
@property(readonly) long long createTime_sec;
@property(readonly) long long createTime_nsec;
@property(readonly) uint32_t st_nlink;
@property(readonly) int st_ino;
@end
