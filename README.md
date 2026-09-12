Smart-Railway-Platform-Announcement-System
📖 Table of Contents

- 📌 Project Overview
- 🎯 Objectives
- 🖼️ Block Diagram
- 🏗️ System Architecture
- ⚙️ Hardware Requirements
- 💻 Software Requirements
- 📂 Repository Structure
- 🖥️ LCD Output Gallery
- ✨ Features
- ▶️ Build Instructions
- 📈 Future Enhancements
- 👤 Author

📌 Project Overview

This project implements a **Smart Railway Platform Clock & Announcement Controller** on an **LPC2148 (ARM7TDMI-S)** microcontroller.The system automatically manages train schedule monitoring, real-time clock synchronization, delay indication, and passenger information display — reducing manual station-announcement effort and improving the accuracy of passenger information.

The controller continuously compares the **on-chip RTC** time against a stored **train schedule database** and automatically updates the LCD dashboard, status LEDs, and buzzer without requiring operator intervention. An administrator can pause normal operation at any time (via an interrupt-driven edit switch) to correct the RTC or amend a train's schedule using a 4×4 matrix keypad, then resume live monitoring — **no system restart required**.

🎯 Objectives

- ✅ Display the current date and time obtained from the RTC on the LCD
- ✅ Allow train schedule entry/editing using a 4×4 matrix keypad
- ✅ Store multiple train arrival and departure timings
- ✅ Continuously compare the RTC time with the scheduled train timings
- ✅ Automatically display the upcoming train information on the LCD
- ✅ Indicate train delays by comparing scheduled vs. updated timings
- ✅ Provide LED indications representing train status (On-Time, Approaching, Delayed)
- ✅ Allow authorized editing of train schedules through the keypad
- ✅ Automatically update the platform display based on the RTC
- ✅ Reduce manual intervention and improve passenger information accuracy

🖼️ Block Diagram

                 ┌───────────────────────────────┐
   KEYPAD ─────► │                                 │
   (4x4)         │                                 │──────► LCD (16x2)
                 │                                 │
                 │           LPC2148                │──────► GREEN LED  (On-Time)
   ADMIN SW ───► │   [ RTC | EINT | GPIO | CORE ]   │──────► YELLOW LED (Approaching)
   (EINT0)       │                                 │──────► RED LED    (Delayed)
                 │                                 │
                 │                                 │──────► BUZZER
                 └───────────────────────────────┘

**Flow:** RTC → compare with `TrainDB[]` → classify status → render LCD dashboard → drive LED/buzzer. An EINT0 falling edge from the admin switch pauses this loop and hands control to the keypad-driven `AdminEditMode()`.

🏗️ System Architecture

  | Module | Function |

| 🕒 RTC Driver | Maintains and reports current date/time (on-chip LPC2148 RTC peripheral) |
| 🖥️ LCD Driver | Renders the passenger dashboard and admin-mode screens (16×2, 8-bit) |
| ⌨️ Keypad Driver | 4×4 matrix scan for admin train-select / digit entry |
| 🚨 EINT0 Driver | Interrupt-driven admin-edit switch, sets a flag consumed by the main loop |
| 🚦 LED/Buzzer Driver | Visual + audible train status indication |
| 🗄️ Train Database | In-memory schedule table (`TrainInfo_t[TOTAL_TRAINS]`) |
| 🧠 Project Logic | Next-train selection, status classification, dashboard rendering, admin edit flows |



