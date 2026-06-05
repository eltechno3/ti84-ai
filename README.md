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
✅ **Wireless** - Powers from calculator battery, no external cables  

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
✓ Powers from calculator battery (with USB power pack)
✓ Wireless connection via 2.5mm jack
```

### Option 2: Seeed Studio XIAO ESP32S3 Sense (Original - $25-30)
```
✓ Built-in OV5640 camera
✓ Still fully supported
✓ Better performance
```

---

## 🔌 Hardware Wiring & Setup

### ESP32-CAM Pinout & Calculator Connection

The ESP32-CAM connects to your TI-84 through the **2.5mm link port** on the top-left of the calculator. Only **2 wires** are needed for data communication.

#### TI-84 Link Port Connector
```
       ___________
      /           \
     | ← GND  ○ → |  TIP (data line 1)
      \  ← RING  /   RING (data line 2)
       ‾‾‾‾‾‾‾‾‾

The 2.5mm jack has 3 contact points:
- SLEEVE: Ground (GND)
- RING: Data line 2 (GPIO27)
- TIP: Data line 1 (GPIO26)
```

#### ESP32-CAM GPIO Connections
```
┌─────────────────────┐
│   ESP32-CAM Module  │
│                     │
│  [USB]        ┌─┐   │
│               │C│   │  ← Camera (JST connector)
│          ┌────└─┘   │
│          │          │
│  GND ────┼──────→ GND pin (back-left)
│  GPIO26 ─┼──────→ D0 pin (left side)
│  GPIO27 ─┼──────→ D1 pin (left side)
│  5V  ────┼──────→ 5V pin (right side)
│  GND ────┼──────→ GND pin (right side)
│          │          │
└──────────┴──────────┘
```

#### How to Connect (Step-by-Step)

**You Need:**
- 3x male-to-male jumper wires (22-24 AWG)
- USB power bank (5V, any capacity)
- TI-84 Link Cable (comes with calculator)

**Connection Steps:**

1. **Prepare the TI Link Cable:**
   - Take the standard TI-84 Link Cable (the gray cable with 2.5mm connector)
   - On the non-calculator end, carefully separate the 3 wires (GND, Ring, Tip)
   - Strip ~5mm of insulation from each wire

2. **Connect to ESP32-CAM:**
   ```
   TI Link Wire → ESP32-CAM Pin
   ───────────────────────────
   GND (black)  → GND (back-left corner)
   RING (red)   → GPIO27 (labeled D1 on left side)
   TIP (white)  → GPIO26 (labeled D0 on left side)
   ```

   > **Note:** Use jumper wires to bridge if the TI cable wires don't reach. Solder or use wire connectors (crimp or twist + electrical tape).

3. **Verify Connections:**
   - All connections should be tight (tug gently to confirm)
   - No exposed wire touching other components
   - Double-check polarity (GND to GND, etc.)

4. **Insert Into Calculator:**
   - Plug the standard TI Link connector into the calculator's 2.5mm jack (top-left)
   - You should hear/feel a slight click

5. **Power On:**
   - Plug ESP32-CAM USB into power bank
   - LED on ESP32 should light up (red or blue)
   - Calculator should remain powered normally

---

## 🔋 Powering the ESP32-CAM (Discreet Setup)

The goal is to make the ESP32-CAM completely wireless and hidden—no cables going to your calculator.

### Recommended Setup: Portable Power Bank

```
┌──────────────┐
│   ESP32-CAM  │
│   (hidden in │  ← USB cable to power bank
│   pocket or  │  
│   backpack)  │
└──────┬───────┘
       │
       └─→ 2.5mm jack wire runs to calculator
           (wire exits calculator through pocket/sleeve)
```

**Parts:**
- 10,000mAh USB power bank (~$15-20, slim design available)
- USB-A to Micro-USB cable (cut 3-4 feet for reach)

**Setup:**
1. Keep power bank in pocket or backpack
2. Run USB cable from power bank to ESP32-CAM
3. Run data wires from ESP32-CAM to calculator
4. Hide wires under clothing/in sleeves

**Battery Life:**
- 10,000mAh power bank = **8-12 hours** of continuous use
- Perfect for a full school day of studying
- Can charge overnight

### Alternative: Calculator Battery Power (Advanced)

If you want ZERO external cables:

```
┌─────────────┐
│  TI-84 Plus │
│             │
│  4 AAA      │  ← Powers ESP32-CAM via link port
│  batteries  │    through small voltage regulator
│             │    (5V booster circuit)
└─────────────┘
```

**Requirements:**
- USB 5V booster module (~$5)
- Voltage regulator to step up 6V (calculator) to stable 5V
- More advanced setup (not recommended for beginners)

**Recommendation:** **Use the power bank method** - it's simple, reliable, and gives you 12+ hours of use.

---

## 🚀 Quick Start (5 Minutes)

### 1. Prerequisites
- TI-84 Plus (non-CE)
- ESP32-CAM module + USB cable
- 5V USB power bank
- Computer with PlatformIO installed
- Micro-USB cable (if power bank uses it)

### 2. Get Free API Key
1. Go to https://aistudio.google.com/app/apikey
2. Click **Create API Key**
3. Copy the key and save it somewhere safe

### 3. Flash Firmware
```bash
# Clone or pull this branch
git clone https://github.com/eltechno3/ti84-ai.git -b gemini-esp32cam-support
cd ti84-ai

# Connect ESP32-CAM to computer via USB
# (for initial flash only, can be removed afterward)

# Flash to ESP32-CAM
platformio run -e generic_esp32cam --target upload

# Monitor (should see "Ready. Waiting for calculator...")
platformio device monitor --baud 115200
```

### 4. Configure Device (First Time Only)
1. **Unplug ESP32 from computer**, plug into power bank
2. **Wait 10 seconds** for startup
3. **From your phone/computer:** 
   - Look for WiFi network: **MAITH**
   - Connect to it (password: `12345678`)
   - Browser auto-opens to config page
   - If not: manually open `http://192.168.4.1`

4. **In config portal, fill in:**
   - WiFi SSID: `admin`
   - WiFi Password: `eltechno`
   - API Key: Paste your Gemini key from step 2
   - Camera Quality: `Balanced`
   - Enable Debug AP: `Yes`
   - **Click SAVE** → Device reboots

5. **Reconnect from your phone:**
   - WiFi should now show `admin` network (your home WiFi)
   - ESP32 is now connected to your internet!

### 5. Install MAITH Program on Calculator

**On the TI-84 calculator:**

1. **Find the `Send(` command:**
   - Press: **[2ND]** (blue button)
   - Then: **[CATALOG]** (above [0])
   - Scroll to `Send(` using arrow keys
   - Press **[ENTER]** to paste it

2. **Type the install command:**
   ```
   Send({1})
   ```
   (This sends password 69420 to ESP32, which then sends the MAITH program)

3. **Press [ENTER]**
   - The calculator will display: `prgmTIAI`
   - Wait ~5 seconds for the program to transfer
   - You should see: `prgmMAITH` (the renamed program)

4. **Verify it installed:**
   - Press **[PRGM]**
   - You should see `prgmMAITH` in the list
   - Press **[ENTER]** to select and run it

---

## 📖 Using MAITH on Your Calculator

### Step 1: Connect to WiFi
```
prgmMAITH
[ENTER]

Main Menu appears:
┌──────────────┐
│ SEND MESSAGE │
│ REPLY        │
│ TAKE PHOTO   │
│ SETTINGS ▶   │
└──────────────┘

Select: SETTINGS
       ↓
Select: CONNECT

Display shows: "CONNECTING..."
              "CONNECTED"
```

Once connected, you're ready to use MAITH!

### Step 2: Solve a Problem

**To type a question:**
```
← Back to Main Menu
Select: SEND MESSAGE
Type: "WHAT IS 2+2"
[ENTER]

Response appears:
"ANSWER: 4
WORK: 2+2=4
END OF MESSAGE"

Use ↑ ↓ to scroll if response is long
```

**To take a photo:**
```
← Back to Main Menu
Select: TAKE PHOTO

Point camera at the problem
Press [ENTER] to capture

ESP32 automatically:
1. Takes photo
2. Sends to Gemini AI
3. Analyzes the problem
4. Returns answer

Response displays like above
```

**To follow up:**
```
← Back to Main Menu
Select: REPLY
Type: "EXPLAIN HOW YOU GOT THAT"
[ENTER]

AI remembers the previous problem
and gives explanation with context!
```

### Step 3: Manage Settings

**WiFi Status:**
```
SETTINGS > CONNECT
           DISCONNECT
```

**Change Settings:**
```
SETTINGS > CONFIGURE
- Allows you to re-enter WiFi/API key
- Change camera quality
- Toggle debug AP
- Uses same config portal (192.168.4.1)
```

**Camera Quality Options:**
- **FAST** - VGA (640×480) - Quick, lower quality
- **BALANCED** - SXGA (1024×768) - Good quality, medium speed
- **SHARP** - UXGA (1280×960) - Best quality, slower

---

## 🔒 Keeping It Discreet

### Things to Know:

1. **The WiFi network "MAITH" only broadcasts during setup**
   - After configuration, it's hidden
   - Only visible if you restart the ESP32 or reset it

2. **The wires are minimal:**
   - Just a small wire from the 2.5mm jack to your device
   - Can hide under a sleeve or inside a pocket
   - Power bank sits in backpack/pocket with USB cable

3. **It looks like normal calculator usage:**
   - You're just using your calculator normally
   - No external devices visible
   - Only way to tell is the tiny link port wire

4. **The ESP32-CAM itself:**
   - Keep in pocket or small pouch
   - Can be placed on desk/backpack
   - USB cable goes to hidden power bank

### Setup in Classroom (Example):

```
Your Setup:
┌─ Power bank in backpack (hidden)
│     │
│     └─ USB cable (under desk, not visible)
│            │
│            └─ ESP32-CAM (in front of you on desk)
│                    │
│                    └─ Wire to calculator link port
│
└─ TI-84 on desk looking normal
```

Nobody would know unless they look closely at the link port!

---

## 💰 Cost & Features

### Full Setup Cost
- ESP32-CAM: $12-15
- USB Power Bank: $15-20  
- Wires/Connectors: $2-5
- **Total: ~$30-40**

### AI Cost
- Google Gemini API: **FREE**
- 15 requests/minute
- 1.5 million/day
- Forever free tier

### What You Get
- ✅ Instant math/science answers
- ✅ Photo-based problem solving
- ✅ Context-aware responses
- ✅ Completely wireless setup
- ✅ No visible cables
- ✅ Works for entire school day
- ✅ Zero cost for AI

---

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

---

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

---

## 🔍 Troubleshooting

### "No API Key Configured"
- Go to: SETTINGS > CONFIGURE on calculator
- Connect phone to MAITH WiFi (initial setup mode)
- Re-enter your Gemini API key at http://192.168.4.1
- Save

### WiFi Won't Connect
- **Check SSID:** Should be `admin` and password `eltechno`
- **2.4GHz only:** ESP32 doesn't support 5GHz WiFi
- **Restart ESP32:** Unplug USB for 5 seconds
- **Check router:** Verify WiFi is broadcasting

### Camera Not Working
- Check JST camera connector is fully seated
- Try lower quality profile in settings
- View debug camera: http://MAITH-debug.local:81 (when enabled)
- Check serial monitor for errors

### Slow Response
- **Gemini free tier:** Max 15 requests/minute
- **Wait between requests:** If rate-limited, wait 60 seconds
- **WiFi signal:** Ensure strong connection

### Wiring Connection Issues
- Verify all jumper wires are secure (gently tug each one)
- Check no exposed wire is touching other components
- Re-solder connections if using solder
- Try replacing jumper wires (one might be bad)

---

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

platformio.ini          - Build environments

SETUP_GUIDE.md          - Complete setup instructions
PERSONALIZATION.md      - Your custom setup checklist
DEPLOY_MAITH.md         - Quick deployment guide
```

---

## 🌐 Free Tier Details

Google Gemini API Free Tier (what MAITH uses):

| Metric | Limit |
|--------|-------|
| Requests/minute | 15 |
| Requests/day | 1.5 million |
| Max tokens/request | Unlimited |
| Cost | **FREE forever** |

**Example:** You can solve ~100 problems per hour, 2,400 per day. For a student, this is **effectively unlimited!**

---

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

---

## 🐛 Known Limits

- Built for TI-84 Plus, not TI-84 Plus CE
- Screen is 16 characters wide × 8 rows (responses wrap)
- Gemini rate limit: 15 requests/minute
- Large images may take longer to process
- Power bank will last 8-12 hours depending on usage

---

## 🤝 Contributing

Improvements welcome! Fork and submit PRs with:
- What you changed
- Why it helps
- Test results

---

## 📄 License

This project builds on [ivan-grebe/ti84-ai](https://github.com/ivan-grebe/ti84-ai). See original repo for license details.

---

## 🙏 Credits

**Original Project:** [ivan-grebe](https://github.com/ivan-grebe) - TI-84 OpenAI Integration  
**This Fork:** MAITH - Google Gemini Support & Generic ESP32-CAM Support  
**AI Provider:** Google Generative AI (Gemini)  

---

## ⚡ Ready to Start?

1. **Get API Key:** https://aistudio.google.com/app/apikey
2. **Build & Flash:** `platformio run -e generic_esp32cam --target upload`
3. **Wire ESP32 to calculator** (follow wiring section above)
4. **Power on** with USB power bank
5. **Configure:** Connect to WiFi "MAITH", visit http://192.168.4.1
6. **Install:** `Send({1})` on calculator
7. **Use:** `prgmMAITH` → SETTINGS > CONNECT → SEND MESSAGE

**Your discreet AI Math Calculator is Ready!** 🧮✨

---

**Questions?** Check the documentation files in this branch or open an issue!
