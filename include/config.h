#pragma once

#include <stdint.h>

// Link port pins (2.5mm jack)
#define PIN_TIP   D0
#define PIN_RING  D1

// Authentication - DO NOT CHANGE
#define PASSWORD  69420

// Display and pagination
#define SCREEN_WIDTH  16

// ============================================================================
// PRE-CONFIGURED FOR: MAITH
// User: eltechno3
// Hardware: ESP32-CAM (generic OV2640)
// AI: Google Gemini (FREE)
// WiFi: admin / eltechno
// ============================================================================

// AI PROVIDER - Google Gemini (FREE, 15 req/min, 1.5M/day)
#define AI_PROVIDER_GEMINI 1
//#define AI_PROVIDER_OPENAI 0

#ifdef AI_PROVIDER_GEMINI
#define AI_HOST   "generativelanguage.googleapis.com"
#define AI_PATH   "/v1beta/models/gemini-2.0-flash:generateContent"
#define AI_MODEL  "gemini-2.0-flash"
#else
#define AI_HOST   "api.openai.com"
#define AI_PATH   "/v1/responses"
#define AI_MODEL  "gpt-4o-mini"
#endif

// CAMERA CONFIGURATION - Generic ESP32-CAM (standard OV2640)
#define CAMERA_TYPE_GENERIC_ESP32CAM 1
//#define CAMERA_TYPE_XIAO_OV5640 0

// Camera settings - Balanced profile (good for all lighting)
#define CAM_XCLK_FREQ      20000000
#define CAM_JPEG_QUALITY   7
#define CAM_FRAMESIZE      FRAMESIZE_SXGA
#define CAM_PROFILE_LOW       0
#define CAM_PROFILE_BALANCED  1
#define CAM_PROFILE_HIGH      2
#define CAM_PROFILE_DEFAULT   CAM_PROFILE_BALANCED

// WiFi AP configuration
#define AP_SSID        "MAITH"
#define AP_PASS        "12345678"
#define AP_IP          IPAddress(192, 168, 4, 1)

// Debug AP (enabled for troubleshooting)
#define DEBUG_AP_SSID  "MAITH-CAM"
#define DEBUG_AP_PASS  "12345678"
#define DEBUG_AP_IP    IPAddress(192, 168, 8, 1)

// NVS storage keys
#define NVS_NAMESPACE  "maith"
#define NVS_KEY_SSID   "wifi_ssid"
#define NVS_KEY_PASS   "wifi_pass"
#define NVS_KEY_APIKEY "api_key"
#define NVS_KEY_DEBUGAP "debug_ap"
#define NVS_KEY_CAMPROF "cam_prof"
#define NVS_KEY_EAP_IDENTITY "eap_id"
#define NVS_KEY_PHOTORECAP "photo_recap"
#define DEFAULT_DEBUG_AP_ENABLED true
#define DEFAULT_PHOTO_RECAP_ENABLED false

static inline uint8_t normalizeCameraProfileValue(uint8_t profile) {
    switch (profile) {
        case CAM_PROFILE_LOW:
        case CAM_PROFILE_BALANCED:
        case CAM_PROFILE_HIGH:
            return profile;
        default:
            return CAM_PROFILE_DEFAULT;
    }
}

// ============================================================================
// SYSTEM PROMPTS - Optimized for TI-84 calculator display
// ============================================================================

#define SYSTEM_PROMPT \
    "YOU ARE MAITH - MATH AI IN A TI-84. " \
    "SCREEN: 16 CHARS, 8 ROWS. " \
    "YOU SOLVE: MATH, PHYSICS, CHEMISTRY. " \
    "RULES:\n" \
    "- ANSWER FIRST. SHORT.\n" \
    "- MULTIPLE ANSWERS: LEFT-TO-RIGHT.\n" \
    "- FOR TABLES/BLANKS: ONE ANSWER PER LINE.\n" \
    "- LABEL ALL ANSWERS.\n" \
    "- NO MARKDOWN. NO SPECIAL CHARS.\n" \
    "- ASCII MATH: ^ FOR POWER, * FOR MULT.\n" \
    "- AVOID: # $ % & ; @ _ ` | ~\n" \
    "- FOR GRAPHS: DESCRIBE IN WORDS.\n" \
    "- THEN SHOW WORK.\n" \
    "- KEEP UNDER 400 CHARS.\n" \
    "- END WITH: END OF MESSAGE."

#define CAMERA_PROMPT \
    "SOLVE THE PROBLEM IN THIS PHOTO. " \
    "TRY YOUR BEST. " \
    "IF UNCLEAR, SAY WHAT'S HARD TO READ. " \
    "ANSWER FIRST, THEN WORK. " \
    "ONE LABELED ANSWER PER LINE. " \
    "NO MARKDOWN. NO SPECIAL CHARS. " \
    "ASCII MATH ONLY. " \
    "END WITH: END OF MESSAGE."

#define CAMERA_RECAP_SUFFIX \
    "START WITH: TRANSCRIPTION: " \
    "THEN RESTATE THE PROBLEM IN PLAIN WORDS. " \
    "THEN SOLVE IT."
