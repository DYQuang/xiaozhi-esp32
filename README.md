# 🧠 Xiaozhi ESP32 Project  
**Hướng dẫn cấu hình, build và nạp firmware cho dự án ESP32 sử dụng ESP-IDF**  
*Biên soạn và hiệu chỉnh bởi Nguyễn Duy Quang*

---

## 📋 Giới thiệu
Dự án **Xiaozhi ESP32** được phát triển dựa trên nền tảng **ESP-IDF**, hỗ trợ nhiều dòng chip như **ESP32**, **ESP32-S3**, **ESP32-C3**, v.v.  
Mục tiêu của dự án là xây dựng hệ thống linh hoạt có thể:

- Tùy chỉnh ngôn ngữ hiển thị.  
- Chọn loại board phần cứng phù hợp.  
- Dễ dàng cấu hình và mở rộng các chức năng như màn hình OLED, LCD, âm thanh, cảm biến, Wi-Fi, OTA, và nhiều hơn nữa.

---

## ⚙️ Cấu hình dự án

### 1. Cấu hình ngôn ngữ và board
Tất cả cấu hình chính nằm trong file: Kconfig.projbuild

Trong đó bạn có thể:

- Chọn **ngôn ngữ mặc định** (Vietnamese, English, Chinese, v.v.)  
- Chọn **Board Type** phù hợp với mạch thật của bạn.  
- Cấu hình **OTA URL**, **Wi-Fi provisioning**, âm thanh, camera, v.v.

Chạy lệnh:idf.py menuconfig điều hướng đến Xiaozhi Assistant → Board Type
trong thư mục board chú ý
| File           | Mục đích                                                                             |
| -------------- | ------------------------------------------------------------------------------------ |
| `config.h`     | Định nghĩa chân GPIO, cấu hình I2C, I2S, SPI, LED, nút bấm...                        |
| `board_xxx.cc` | Khởi tạo và chạy các chức năng đặc trưng của board (âm thanh, hiển thị, cảm biến...) |


🧱 Quy trình build và nạp firmware
🪜 Bước 1. Mở ESP-IDF Terminal

Mở ESP-IDF Command Prompt hoặc VS Code Terminal đã cài đặt ESP-IDF.

🗂️ Bước 2. Di chuyển đến thư mục dự án
cd "D:/xiaozhi-esp32-main"

⚙️ Bước 3. Kiểm tra cấu hình
idf.py menuconfig

Kiểm tra lại cấu hình board, ngôn ngữ, OTA, v.v.

🧱 Bước 4. Build project
idf.py build

Tạo file firmware .bin, .elf, .map trong thư mục build/.

🔥 Bước 5. Nạp firmware vào ESP32
idf.py -p COMx flash

Thay x bằng số cổng thực tế, ví dụ COM3.

📟 Bước 6. Mở monitor để xem log
idf.py -p COM3 monitor

Nhấn Ctrl + ] để thoát khỏi chế độ monitor.
