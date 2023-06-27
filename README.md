# OOP-Project-Game_Console
# Yêu cầu tổng quan:
- Xây dựng mô phỏng lại game đấu Hero trên consol (không cần có giao diện đồ họa).
- Input: Danh sách các Hero của các bên tham gia hiệp đấu.
- Output: Kết quả trận đấu (Thắng hay hòa; Thắng thì ai là người thắng) in ra màn hình. Ngoài in kết quả thắng thua còn in danh sách và chỉ số của các hero trong trận đấu.
# Mô tả game play:
- Xem file đính kèm “ListHero.txt”.
- Chương trình khi khời động sẽ load các hero từ “ListHero.txt” và lưu trong một danh sách (list/vector).
- Mỗi dòng trong file là info của một hero; có cấu trúc như sau:
      <tên hero>;<thuộc tính>;<Máu>;<Công>;<thủ>;<tốc độ>
- Ví dụ: Treant Protector;Wood;700;62;1.5;38
- Danh sách Hero có thể được cập nhật/thêm mới từ bán phím và được lưu trữ tại file “ListHero.txt”
# Kết quả:
- Kết quả sẽ được in ra màn hình và tự động lưu vào vào file Log.txt.
- Mỗi dòng là thông tin của 1 hiệp đấu.
-	Thông tin được lưu trữ theo cấu trúc sau: <thời gian gio/phut/giay/ngày/tháng/nam><Ten người chơi 1|NPC><Danh sách Hero của người chơi 1|NPC><Người chơi 2>< Danh sách Hero của người chơi 2><kết quả>
-	Người chơi có thể xem lịch sử lưu trong file log (chỉ in thời gian ra màn hinh); nếu muốn xem chi tiết thông tin của hiệp đấu nào đó, thì người chơi cung cấp thời gian từ bàn phím.
# Mô tả hệ thống quản lý người chơi:
![image](https://github.com/tienanhjkl/OOP-Project-Game_Console/assets/69162614/17360c6b-801e-4769-bff5-9726d3af9def)
# Yêu cầu kỹ thuật:
  1.	Tên biến/Hàm/Class…
- Đặt tên biến tiếng việt có nghĩa (trừ các biến liên quan đến tên của Hero)
- Tuân theo quy tắc lạc đà trong đặt tên nhưng có sự phân loại tên có biến/hàm/class … Tức là có quy tắc đặt tên riêng cho mỗi loại.
Ví dụ:
    Biến toàn cục thì viết hoa toàn bộ từ đầu tiên.
    Biến hình thức thì viết hoa các chữ cái mỗi từ
  2.	Hàm xừ lý
- Ưu tiên lấy kết quả trong quá trình xử lý trong hàm bằng cách cho hàm trả về kết quả.
- Hạn chế sử dụng biến tham chiếu đề lấy kết quả xử lý trong hàm
  3.	Tổ chức project
- Tổ chức ít nhất 3 file:
  File *.h : chứa phần khai báo.
  File Source.cpp: Chứa phần định nghĩa.
  File Main.cpp: Chứa hàm main
  4.	Lưu trữ dữ liệu
- Dữ liệu trong file txt.
- Tất cả các file txt được đặt trong cùng cấp folder project
  5.	Kiến trúc code.
- Thể hiện được 4 tính chất của OOP
  6.	Quy tắc trình bày code
-	Không để dòng trống.
-	Thụt đầu dòng.
-	Phải xuống dòng khi mở ngoặc và đóng ngoặc.
-	Phải có chú thích cho từng hàm ở cả phân prototype và phần định nghĩa.
