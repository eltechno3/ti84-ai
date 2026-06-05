## TI-84 AI: Gemini & Generic ESP32-CAM Setup Guide

This branch adds support for **Google Gemini** (FREE AI) and **generic ESP32-CAM** modules, while maintaining backward compatibility with the original OpenAI + XIAO setup.

---

## Quick Start (5 minutes)

### 1. Choose Your Hardware

**Option A: Generic ESP32-CAM (~$12)**
- Standard pinout (works with most cheap ESP32-CAM boards)
- Supported in this branch ✅

**Option B: Seeed Studio XIAO ESP32S3 Sense (Original, ~$30)**
- Still fully supported ✅
- Configure in `include/config.h`

### 2. Get Free AI API Key (Google Gemini)

1. Go to https://aistudio.google.com/app/apikey
2. Click **Create API Key**
3. Copy and save your key
4. Free tier: 15 requests/minute, 1.5M requests/day (plenty for a calculator!)

### 3. Configuration

In `include/config.h`, choose your setup:

```c
// ============================================================================
// AI PROVIDER SELECTION
// ============================================================================
// For FREE Google Gemini (default):
#define AI_PROVIDER_GEMINI 1
//#define AI_PROVIDER_OPENAI 0

// OR for paid OpenAI:
//#define AI_PROVIDER_GEMINI 0
//#define AI_PROVIDER_OPENAI 1

// ============================================================================
// CAMERA CONFIGURATION
// ============================================================================
// For generic ESP32-CAM (default):
#define CAMERA_TYPE_GENERIC_ESP32CAM 1
//#define CAMERA_TYPE_XIAO_OV5640 0

// OR for XIAO ESP32S3 Sense:
//#define CAMERA_TYPE_GENERIC_ESP32CAM 0
//#define CAMERA_TYPE_XIAO_OV5640 1
```

### 4. Build & Flash

```bash
# For generic ESP32-CAM with Gemini:
platformio run -e generic_esp32cam --target upload

# For XIAO ESP32S3 with Gemini:
platformio run -e xiao_esp32s3 --target upload

# Monitor serial output:
platformio device monitor --baud 115200
```

### 5. First-Time Setup (on calculator)

1. On calculator home screen: `Send({1})` and press ENTER
   - To find `Send(`: press **[2ND]** > **[CATALOG]** > **[LN]** > scroll to `Send(`
2. Run `prgmTIAI`
3. Go to **SETTINGS > CONFIGURE**
4. Connect to **TI84AI** network (password: `12345678`)
5. Enter:
   - WiFi SSID and password
   - **Your Gemini API Key** (from step 2)
   - Camera quality (defaults to Balanced - good for most setups)
   - Enable debug AP (optional)
6. Save → ESP32 reboots
7. Go back to calculator, **SETTINGS > CONNECT**

You're ready! Use:
- **SEND MESSAGE** to ask questions
- **REPLY** to follow up (context-aware)
- **TAKE PHOTO** to solve math problems in photos
- **↑/↓** to scroll through responses

---

## Detailed Configuration

### Camera Selection

#### Generic ESP32-CAM Pinout
```
GND   - GND
5V    - 5V
U0R   - USB RX
U0T   - USB TX
GPIO16 - (unused)
GPIO25 - VSYNC
GPIO23 - HREF
GPIO22 - PCLK
GPIO21 - Y5
GPIO19 - Y4
GPIO18 - Y3
GPIO5  - Y2
GPIO4  - (unused)
GPIO0  - XCLK
GPIO26 - SDA
GPIO27 - SCL
GPIO35 - Y9
GPIO34 - Y8
GPIO39 - Y7
GPIO36 - Y6
GPIO2  - (unused)
GPIO32 - PWDN
GND    - GND
```

#### XIAO ESP32S3 Sense OV5640
Pre-configured in this branch - just set `CAMERA_TYPE_XIAO_OV5640 1`

### AI Provider Comparison

| Provider | Cost | Free Tier | Quality | Setup |
|----------|------|-----------|---------|-------|
| **Google Gemini** | FREE | Yes | Excellent | 1 API key |
| **OpenAI GPT-4o Mini** | $0.03/req | No | Excellent | Credit card |
| **OpenAI GPT-4 Vision** | $0.015/req | No | Best | Credit card |

**Recommendation:** Start with **Gemini** (free). Upgrade to OpenAI if you need better responses.

---

## Hardware Wiring

### Generic ESP32-CAM to TI-84 Calculator

Only 2 wires needed from ESP32 to calculator's 2.5mm link port:

```
ESP32-CAM GPIO26 (SDA) → TI Link Ring
ESP32-CAM GPIO27 (SCL) → TI Link Tip
ESP32-CAM GND        → TI Link Sleeve (via resistor or cap)
```

### Generic ESP32-CAM to USB Power

Use any USB power supply (5V):
```
USB 5V+ → ESP32-CAM 5V pin
USB GND → ESP32-CAM GND pin
```

---

## Troubleshooting

### "No API key configured"
- **Fix:** Go to Calculator → SETTINGS → CONFIGURE
- Enter your Gemini API key
- Save and reboot

### "DNS/NET ERROR" or "WIFI FAILED"
- Check WiFi SSID/password
- Verify router is 2.4GHz (ESP32 doesn't support 5GHz)
- Restart ESP32 (unplug USB)
- Check serial monitor: `platformio device monitor --baud 115200`

### Camera not working / "CAMERA FAIL"
1. Check physical connections (JST camera connector for generic ESP32-CAM)
2. Verify pins match `include/camera_pins.h`
3. Try lower quality profile in config portal
4. Check serial logs for camera init errors

### Responses are cut off
- Calculator screen is only 16 chars × 5 rows
- Responses are automatically wrapped and scrollable
- Use ↑/↓ arrow keys to scroll
- Adjust system prompt in `config.h` for more concise responses

### Slow response time
- **Gemini:** 15 req/min free tier - wait between requests
- **OpenAI:** No rate limit (paid)
- Network latency - ensure good WiFi signal

---

## File Changes Summary

**New Files:**
- `src/gemini_client.h` - Generic AI client (Gemini/OpenAI)
- `SETUP_GUIDE.md` - This guide

**Modified Files:**
- `include/config.h` - AI provider + camera type selection
- `include/camera_pins.h` - Conditional pin selection
- `src/main.cpp` - Updated to use generic AI namespace
- `platformio.ini` - Added generic_esp32cam environment

**Original Files (unchanged but compatible):**
- Everything else works as before!

---

## Advanced: Custom Prompts

Edit `include/config.h` to customize AI behavior:

```c
#define SYSTEM_PROMPT \
    "Your custom prompt here..."

#define CAMERA_PROMPT \
    "Custom photo analysis instructions..."
```

Keep responses concise (under 400 chars) for calculator display.

---

## Cost Examples

**Monthly usage estimate** (doing homework):

| Scenario | Gemini | OpenAI Mini |
|----------|--------|-------------|
| 1 photo/day | FREE | $0.90/mo |
| 10 prompts/day | FREE | $0.60/mo |
| 20 photos/day | FREE | $18/mo |
| 100+ daily | FREE | $50+/mo |

Gemini free tier: **1.5 million requests/day** ✅

---

## Support & Issues

If something doesn't work:

1. Check `SETUP_GUIDE.md` troubleshooting
2. Review `include/config.h` settings
3. Check serial monitor: `platformio device monitor --baud 115200`
4. Look for errors in config portal (http://192.168.4.1 during initial setup)

---

## Contributing

Have improvements? Fork and submit a PR with:
- What you changed
- Why it helps
- Test results

---

**Enjoy your AI-powered calculator!** 🧮✨
