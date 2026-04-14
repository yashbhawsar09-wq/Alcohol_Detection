# 🚗 Alcohol Detection with Engine Lock & GPS Alert System (MQ-3)

## 📌 Project Overview
This project is a **biomedical safety system** designed to prevent drunk driving by detecting alcohol levels in a driver's breath using the MQ-3 sensor. If the alcohol concentration exceeds a predefined threshold, the system automatically **disables the vehicle ignition** and sends a **GPS-based alert** to a registered contact.

The system integrates **embedded systems, sensors, and IoT concepts** to enhance road safety and reduce accident risks.

---

## 🎯 Objectives
- Detect alcohol presence in human breath using MQ-3 sensor  
- Prevent vehicle ignition when alcohol exceeds safe limits  
- Provide real-time alert with location to family/emergency contact  
- Develop a low-cost and reliable embedded safety system  

---

## 🧠 Working Principle
The MQ-3 sensor detects alcohol concentration in air based on changes in resistance.

### When a person breathes near the sensor:
- Alcohol molecules interact with the sensor surface  
- Sensor resistance decreases  
- Analog voltage output increases  

### Microcontroller Decision Logic:
- **If value < threshold → Engine ON**  
- **If value ≥ threshold → Engine OFF + Alert triggered**

---

## 🧩 System Components

### 🔧 Hardware Components
- MQ-3 Alcohol Sensor  
- Microcontroller (Arduino Uno / ESP32)  
- Relay Module (for engine lock simulation)  
- GPS Module (e.g., NEO-6M)  
- GSM Module (e.g., SIM800L)  
- Buzzer (alert system)  
- LED indicators  
- Power supply  

### 💻 Software Requirements
- Arduino IDE  
- Embedded C / C++  
- Serial Communication Libraries  

---

## ⚙️ System Architecture
1. MQ-3 sensor reads alcohol level  
2. Microcontroller processes sensor data  
3. If threshold exceeded:
   - Relay turns OFF ignition  
   - Buzzer activates  
   - GPS fetches location  
   - GSM sends SMS alert  
4. If safe:
   - Engine remains ON  

---

## 🔌 Circuit Description
- MQ-3 analog output → Analog pin of Arduino  
- Relay module → Digital output pin  
- GPS module → UART (TX/RX)  
- GSM module → UART (TX/RX)  
- Buzzer & LED → Digital pins  

---

## 🧮 Threshold Calibration
- Sensor requires preheating (~20 seconds)  
- Threshold value is set experimentally  
- Typical analog range: **200–400** (depends on environment)  
- Calibration is necessary for accurate detection  

---

## 🚀 Features
- Real-time alcohol detection  
- Automatic ignition lock system  
- GPS-based live location tracking  
- SMS alert system  
- Low-cost and scalable design  

---

## ⚠️ Limitations
- MQ-3 is sensitive to other gases (false positives possible)  
- Accuracy depends on calibration  
- Environmental factors (temperature, humidity) affect readings  
- Not legally certified for real-world enforcement  

---

## 🔮 Future Enhancements
- Integration with mobile app (IoT dashboard)  
- Use of advanced sensors for higher accuracy  
- Face recognition for driver identification  
- Cloud data logging and analytics  
- AI-based alcohol level prediction  

---

## 📊 Applications
- Automobile safety systems  
- Fleet monitoring systems  
- Law enforcement support tools  
- Driver safety devices  

---

## 🛠️ How to Run the Project
1. Connect all hardware components as per circuit diagram  
2. Upload code using Arduino IDE  
3. Power the system  
4. Allow sensor to warm up  
5. Test using alcohol (sanitizer, breath, etc.)  
6. Observe ignition control and alert system  

---

## 📚 Conclusion
This project demonstrates how biomedical sensing and embedded systems can be combined to address real-world problems like drunk driving. It provides a **cost-effective, scalable, and practical safety solution** with scope for further research and development.

---

## 👨‍💻 Author
- Name: *Your Name*  
- Course: Biomedical Engineering  
- Semester: 6th  

---

## 📄 License
This project is for academic and educational purposes only.
