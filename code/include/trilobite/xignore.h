/*
   This C header file is part of the Trilobite Stdlib, a collection of utility functions and
   standard data structures for enhancing software development projects. Feel free to use
   and modify these utilities to streamline your software development process.

   Project: Trilobite Stdlib
   Author: Michael Gene Brockus (Dreamer)
   Email: michaelbrockus@gmail.com
   Website: [Trilobite Coder Blog](https://trilobite.code.blog)

   Trilobite Stdlib is designed to provide a robust set of functionalities that can be
   incorporated into various projects. The utilities included in this library aim to optimize
   and standardize common operations, ensuring efficient and reliable code.

   This header file is a part of a broader initiative to support developers in creating secure,
   efficient, and scalable software. Contributions, suggestions, and feedback are welcomed,
   as we strive to continuously improve and expand the capabilities of Trilobite Stdlib.

   License: Apache License 2.0
   SPDX Identifier: Apache-2.0

   Licensed under the Apache License, Version 2.0 (the "License");
   you may not use this file except in compliance with the License.
   You may obtain a copy of the License at

       http://www.apache.org/licenses/LICENSE-2.0

   Unless required by applicable law or agreed to in writing, software distributed under the License
   is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express
   or implied. See the License for the specific language governing permissions and limitations
   under the License.

   The above copyright notice and this permission notice shall be included in all copies or
   substantial portions of the Software.

   Please review the full text of the Apache License 2.0 for the complete terms and conditions.

   (Apache License 2.0: http://www.apache.org/licenses/LICENSE-2.0)
*/
#ifndef TRILOBITE_XIGNORE_H
#define TRILOBITE_XIGNORE_H

#ifdef __cplusplus
extern "C"
{
#endif

#include "xtest.h"

// Define platform-specific macros for desktop platforms

// Windows (32-bit and 64-bit)
#ifdef _WIN32
#define XIGNORE_ON_WINDOWS
#endif

// Linux (Various distributions)
#ifdef __linux__
#define XIGNORE_ON_LINUX
#endif

// macOS (Apple Macintosh)
#ifdef __APPLE__
#define XIGNORE_ON_MACOS
#endif

// FreeBSD (Unix-like OS)
#ifdef __FreeBSD__
#define XIGNORE_ON_FREEBSD
#endif

// OpenBSD (Secure Unix-like OS)
#ifdef __OpenBSD__
#define XIGNORE_ON_OPENBSD
#endif

// NetBSD (Unix-like OS)
#ifdef __NetBSD__
#define XIGNORE_ON_NETBSD
#endif

// Solaris (Unix-based OS)
#ifdef __sun
#define XIGNORE_ON_SOLARIS
#endif

// AIX (IBM's Unix OS)
#ifdef _AIX
#define XIGNORE_ON_AIX
#endif

// HP-UX (Hewlett-Packard Unix)
#ifdef __hpux
#define XIGNORE_ON_HPUX
#endif

// Haiku (Open-source OS inspired by BeOS)
#ifdef __HAIKU__
#define XIGNORE_ON_HAIKU
#endif

// ReactOS (Open-source Windows-compatible OS)
#ifdef __REACTOS__
#define XIGNORE_ON_REACTOS
#endif

// Plan 9 (Distributed OS by Bell Labs)
#ifdef __plan9__
#define XIGNORE_ON_PLAN9
#endif

// Custom desktop OS
#ifdef __CUSTOM_DESKTOP_OS__
#define XIGNORE_ON_CUSTOM_DESKTOP
#endif

// Define platform-specific macros for mobile platforms

// Android
#ifdef __ANDROID__
#define XIGNORE_ON_ANDROID
#endif

// iOS (iPhone, iPad, iPod Touch)
#ifdef __APPLE__
#define XIGNORE_ON_IOS
#endif

// Windows Phone
#ifdef _WIN32
#define XIGNORE_ON_WINDOWS_PHONE
#endif

// BlackBerry
#ifdef __QNX__
#define XIGNORE_ON_BLACKBERRY
#endif

// Tizen
#ifdef __TIZEN__
#define XIGNORE_ON_TIZEN
#endif

// Firefox OS
#ifdef __B2G__
#define XIGNORE_ON_FIREFOX_OS
#endif

// Sailfish OS
#ifdef __SAILFISH__
#define XIGNORE_ON_SAILFISH
#endif

// Ubuntu Touch
#ifdef __UBUNTU_TOUCH__
#define XIGNORE_ON_UBUNTU_TOUCH
#endif

// KaiOS
#ifdef __KAIOS__
#define XIGNORE_ON_KAIOS
#endif

// HarmonyOS (Huawei)
#ifdef __HARMONYOS__
#define XIGNORE_ON_HARMONYOS
#endif

// Custom embedded OS (e.g., feature phone)
#ifdef __CUSTOM_EMBEDDED_OS__
#define XIGNORE_ON_CUSTOM_EMBEDDED
#endif

// Define platform-specific macros for embedded platforms

// ARM Cortex-M series
#if defined(__ARM_ARCH_6M__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7EM__)
#define XIGNORE_ON_CORTEX_M
#endif

// PIC microcontrollers
#if defined(__PIC16__) || defined(__PIC18__) || defined(__PIC32__)
#define XIGNORE_ON_PIC
#endif

// Atmel AVR microcontrollers
#if defined(__AVR__)
#define XIGNORE_ON_AVR
#endif

// Texas Instruments MSP430 series
#if defined(__MSP430__)
#define XIGNORE_ON_MSP430
#endif

// STM32 microcontrollers from STMicroelectronics
#if defined(STM32F0) || defined(STM32F1) || defined(STM32F2)
#define XIGNORE_ON_STM32
#endif

// Nordic Semiconductor nRF series
#if defined(NRF51) || defined(NRF52)
#define XIGNORE_ON_NRF
#endif

// ESP8266 and ESP32
#if defined(ESP8266) || defined(ESP32)
#define XIGNORE_ON_ESP
#endif

#ifdef __cplusplus
}
#endif

#endif
