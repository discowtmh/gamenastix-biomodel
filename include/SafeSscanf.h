// This file is a part of Treadmill project.
// Copyright 2018 Disco WTMH S.A.

#pragma once

#ifdef __WIN32
#define safe_string_scan_formatted sscanf_s
#else
#define safe_string_scan_formatted sscanf
#endif

