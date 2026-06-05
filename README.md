# MAITH - AI Math Calculator for TI-84 Plus

![TI-84 AI](https://img.shields.io/badge/TI--84-AI%20Powered-blue) ![Gemini](https://img.shields.io/badge/AI-Google%20Gemini-red) ![Free](https://img.shields.io/badge/Cost-FREE-brightgreen) ![ESP32](https://img.shields.io/badge/Hardware-ESP32--CAM-orange)

**MAITH** is an AI-powered upgrade for your TI-84 Plus calculator. Solve math, physics, and chemistry problems instantly using FREE Google Gemini AI.

**No subscription. No credit card. 15 requests/minute FREE forever.**

## ✨ Key Features

✅ **FREE AI** - Google Gemini (unlimited free tier)  
✅ **Text & Photos** - Type questions or photograph problems  
✅ **Auto-Solve** - Point camera at equation, get answer instantly  
✅ **Context-Aware** - Reply to follow up with conversation memory  
✅ **Plug & Play** - Pre-configured, just flash and use  
✅ **Generic Hardware** - Works with standard ESP32-CAM boards (~$12)  
✅ **Backward Compatible** - Also supports original Seeed Studio XIAO setup  

## 🎯 What You Get

| Feature | Description |
|---------|-------------|
| **SEND MESSAGE** | Type any math question, get instant answer |
| **REPLY** | Follow up with context (AI remembers previous answers) |
| **TAKE PHOTO** | Point camera at problem, auto-solve |
| **SCROLL** | Use ↑/↓ to navigate long responses |
| **SETTINGS** | WiFi, API key, camera quality, debug mode |

## 📊 Hardware Options

### Option 1: Generic ESP32-CAM (Recommended - $12-15)
```
✓ Standard OV2640 camera
✓ Works worldwide
✓ 2.5mm link wiring to calculator
✓ USB power
```

### Option 2: Seeed Studio XIAO ESP32S3 Sense (Original - $25-30)
```
✓ Built-in OV5640 camera
✓ Still fully supported
✓ Better performance
```

## 🚀 Quick Start (5 Minutes)

### 1. Prerequisites
- TI-84 Plus (non-CE)
- ESP32-CAM module
- USB power supply
- Computer with PlatformIO installed

### 2. Get Free API Key
1. Go to https://aistudio.google.com/app/apikey
2. Click **Create API Key**
3. Copy the key

### 3. Flash Firmware
```bash
# Clone or pull this branch
git clone https://github.com/eltechno3/ti84-ai.git -b gemini-esp32cam-support
cd ti84-ai

# Flash to ESP32-CAM
platformio run -e generic_esp32cam --target upload

# Monitor (should see "Ready. Waiting for calculator...")
platformio device monitor --baud 115200
```

### 4. Configure Device
1. **From phone/computer:** Connect to WiFi **MAITH** (password: `12345678`)
2. Open browser → automatically redirects to `http://192.168.4.1`
3. **Pre-filled settings (verify these):**
   - WiFi SSID: `admin`
   - WiFi Password: `eltechno`
   - API Key: Paste your Gemini key
   - Camera Quality: `Balanced` ✓
   - Debug AP: `Enabled` ✓
4. Click **SAVE** → Device reboots

### 5. Install on Calculator
```
Send({1})
[ENTER]
```
This installs `prgmMAITH`

### 6. Use It!
```
prgmMAITH
[ENTER]
SETTINGS > CONNECT (joins WiFi)
SEND MESSAGE (start solving problems!)
```

## 📋 Pre-Configured Settings

This branch comes with everything pre-filled for **MAITH**:

```c
// App Name
AP_SSID = "MAITH"

// WiFi
WiFi SSID: admin
WiFi Password: eltechno

// AI Engine
Provider: Google Gemini (FREE)
Model: gemini-2.0-flash
Rate: 15 requests/minute

// Hardware
Camera: Generic ESP32-CAM (OV2640)
Quality: Balanced (default)
Debug AP: MAITH-CAM (enabled)

// Prompts
All UPPERCASE optimized for 16-char calculator display
```

**No code changes needed!** Just flash and use.

## 💰 Cost Comparison

| Provider | Cost | Daily Limit | Solving Capacity |
|----------|------|-------------|------------------|
| **Google Gemini** | FREE | 1.5M requests | 21,600+ problems/day |
| **OpenAI GPT-4o Mini** | $0.03/req | Unlimited | Pay per use |
| **OpenAI GPT-4 Vision** | $0.015/req | Unlimited | Pay per use |

**MAITH uses Gemini = FREE forever!** 🎉

## 🔧 Hardware Wiring

### ESP32-CAM to TI-84 Calculator
Only 2 GPIO pins needed:
```
ESP32-CAM GPIO26 (SDA) → TI Link Ring
ESP32-CAM GPIO27 (SCL) → TI Link Tip
ESP32-CAM GND         → TI Link Sleeve (optional, for stability)
```

### Power
```
USB 5V  → ESP32-CAM 5V
USB GND → ESP32-CAM GND
```

## 📁 Repository Structure

```
include/
  config.h              - Pre-filled MAITH settings
  camera_pins.h         - Conditional ESP32-CAM/XIAO pinout
  program_data.h        - TI-BASIC program (generated)

src/
  main.cpp              - Calculator link handling
  gemini_client.h       - Generic AI client (Gemini/OpenAI)
  camera.h              - Camera capture helpers
  wifi_manager.h        - WiFi & config portal
  web_ui.h              - Config UI HTML

tools/
  build_program.py      - TI-BASIC program builder

platformio.ini          - Build environments (generic_esp32cam, xiao_esp32s3)

SETUP_GUIDE.md          - Complete setup instructions
PERSONALIZATION.md      - Your custom setup checklist
DEPLOY_MAITH.md         - Quick deployment guide
```

## 🛠️ Development Setup

### Requirements
1. **Python 3** - https://www.python.org/downloads/
2. **Git** - https://git-scm.com/downloads
3. **PlatformIO** - VS Code extension OR `pipx install platformio`

### Build & Flash

**For Generic ESP32-CAM:**
```bash
platformio run -e generic_esp32cam --target upload
```

**For Original XIAO ESP32S3:**
```bash
platformio run -e xiao_esp32s3 --target upload
```

**Monitor Serial:**
```bash
platformio device monitor --baud 115200
```

## 📖 Using MAITH

### Main Menu
- **SEND MESSAGE** - Ask a math question
- **REPLY** - Follow up (keeps conversation context)
- **TAKE PHOTO** - Photograph a problem, auto-solve
- **SCROLL UP/DOWN** - Navigate responses

### Settings Menu
- **CONNECT** - Join WiFi
- **DISCONNECT** - Leave WiFi
- **CONFIGURE** - Change WiFi, API key, camera quality

### Camera Modes
- **Balanced** - Good for all lighting (default)
- **Fast** - Lower quality, VGA resolution
- **Sharp** - Higher quality, UXGA resolution

## 🔍 Troubleshooting

### "No API Key Configured"
- Go to: SETTINGS > CONFIGURE
- Connect to MAITH WiFi
- Re-enter your Gemini API key
- Save

### WiFi Won't Connect
- **Check SSID:** Should be `admin` and password `eltechno`
- **2.4GHz only:** ESP32 doesn't support 5GHz WiFi
- **Restart device:** Unplug USB for 5 seconds
- **Check router:** Verify WiFi is broadcasting

### Camera Not Working
- Check JST camera connector is fully seated
- Try lower quality profile in config
- View debug camera: http://MAITH-debug.local:81 (when enabled)
- Check serial monitor for errors

### Slow Response
- **Gemini free tier:** Max 15 requests/minute
- **Wait between requests:** If rate-limited, wait 60 seconds
- **WiFi signal:** Ensure strong connection
- **Network latency:** Try from a location closer to WiFi

## 🌐 Free Tier Limits

Google Gemini API Free Tier (what MAITH uses):

| Metric | Limit |
|--------|-------|
| Requests/minute | 15 |
| Requests/day | 1.5 million |
| Max tokens/request | Unlimited |
| Cost | **FREE forever** |

**Example:** You can solve ~100 problems per hour, 2,400 per day. For a student doing homework, this is **unlimited!**

## 🎨 Customization

### Change WiFi Network Name
Edit `include/config.h`:
```c
#define AP_SSID "YOUR_NAME_HERE"
```
(Remember: TI-84 only supports UPPERCASE)

### Adjust AI Behavior
Edit system prompts in `include/config.h`:
```c
#define SYSTEM_PROMPT "YOUR CUSTOM INSTRUCTIONS"
```

### Switch to OpenAI (Paid)
Edit `include/config.h`:
```c
#define AI_PROVIDER_GEMINI 0
#define AI_PROVIDER_OPENAI 1
```

### Use XIAO ESP32S3 Instead
Edit `include/config.h`:
```c
#define CAMERA_TYPE_GENERIC_ESP32CAM 0
#define CAMERA_TYPE_XIAO_OV5640 1
```

## 📖 Documentation Files

- **SETUP_GUIDE.md** - Complete setup with troubleshooting
- **PERSONALIZATION.md** - Your custom checklist
- **DEPLOY_MAITH.md** - Quick deployment reference

## 🐛 Known Limits

- Built for TI-84 Plus, not TI-84 Plus CE
- Screen is 16 characters wide × 8 rows (responses wrap)
- Gemini rate limit: 15 requests/minute
- Large images may take longer to process
- Conversation history not saved across reboots

## 🤝 Contributing

Improvements welcome! Fork and submit PRs with:
- What you changed
- Why it helps
- Test results

## 📄 License

This project builds on [ivan-grebe/ti84-ai](https://github.com/ivan-grebe/ti84-ai). See original repo for license details.

## 🙏 Credits

**Original Project:** [ivan-grebe](https://github.com/ivan-grebe) - TI-84 OpenAI Integration  
**This Fork:** MAITH - Google Gemini Support & Generic ESP32-CAM Support  
**AI Provider:** Google Generative AI (Gemini)  

## ⚡ Ready to Start?

1. **Get API Key:** https://aistudio.google.com/app/apikey
2. **Flash Firmware:** `platformio run -e generic_esp32cam --target upload`
3. **Configure:** Connect to WiFi "MAITH", visit http://192.168.4.1
4. **Install:** `Send({1})` on calculator
5. **Use:** `prgmMAITH` → SETTINGS > CONNECT → SEND MESSAGE

**Your AI Math Calculator is Ready!** 🧮✨

---

**Questions?** Check the documentation files in this branch or open an issue!
