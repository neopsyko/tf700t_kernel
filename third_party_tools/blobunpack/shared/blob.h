/*
* Copyright 2012 Jens Andersen/AndroidRoot.mobi
*
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*
*      http://www.apache.org/licenses/LICENSE-2.0
*
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*   limitations under the License.
*/

#ifndef _BLOB_H
#define _BLOB_H

// Previous unknown fields grabbed from 
// http://nv-tegra.nvidia.com/gitweb/?p=android/platform/build.git;a=commitdiff;h=0adc4478615891636d8b7c476c20c2014b788537

#define SECURE_MAGIC	"-SIGNED-BY-SIGNBLOB-"
#define SECURE_MAGIC_SIZE	20
#define SECURE_OFFSET	28
#define MAGIC       "MSM-RADIO-UPDATE"
#define MAGIC_SIZE  16
#define PART_NAME_LEN 4

typedef struct
{
    unsigned char magic[MAGIC_SIZE];
    unsigned int version; // Always 0x00010000
    unsigned int size; // Size of header
    unsigned int part_offset; // Same as size
    unsigned int num_parts; // Number of partitions
    unsigned int unknown[7]; // Always zero
} header_type;

typedef struct 
{
  unsigned char magic[SECURE_MAGIC_SIZE];
  unsigned int datalen;
  unsigned int siglen;
  header_type real_header;
} secure_header_type;

typedef struct
{
    char name[PART_NAME_LEN]; // Name of partition. Has to match an existing tegra2 partition name (e.g. LNX, SOS)
    unsigned int offset; // offset in blob where this partition starts
    unsigned int size; // Size of partition
    unsigned int version; // Version is variable, but is always 1 in this app
} part_type;

#endif /* _BLOB_H*/
