# **Final Assignment**
*** 
*Hệ Thống Quản Lý Phân Công Giảng Dạy Cho Giáo Viên*
echo 
```
**教師を管理するシステム** 
php
```
***
 ## **Git Bash cơ bản** 
- Tạo mới file git trong máy tính (local Repo):
  * `git init + [tên foler.định dạng]` (lệnh này sẽ tạo 1 foler chứa file ẩn .git)
- Thêm file vào local Repo:
  * `git add + [tên file.định đạng']` (Khi đó file này đã "Staged")
- Thêm tất cả file vào local Repo:
  * `git add .`
- Khi add file vào thì file đã sẵn sàng để commit lên local Repo, khi đó dùng lệnh:
  * `git commit -m + "your commit messenge"`
- Liên kết, đồng bộ local Repo với remote Repo trên gitHub qua lệnh:
  * `git remote add origin + [URL repo gitHub]` ( "Origin là tên mặc định gán cho remote Repo. Thường sử dụng "Origin" cho remote Repo chính.)
- Xem các remote đã liên kết:
  * `git remote -v`
- Lệnh push - pull file từ local Repo lên remote Repo và ngược lại:
  * `git push -u origin <master>` (\<master> là tên nhánh- brach chính của remote Repo) (Ngoài ra sau khi commit file xong thì dùng lệnh này để push lên remote Repo)
  * `git pull -u origin <master>`
- *Trường hợp là người mới dùng git bash, git bash sẽ yêu cầu cấu hình thông tin cá nhân về Authority như username và email để biết ai là người thực hiện lệnh*
  * `git config --global user.name "Tên bạn"`
  *  `git config --global user.mail "Tên mail"`
- *Để kiểm tra cấu hình đã thiết lập:*
  * `git config --global --list`
- **Trường hợp có thằng khác thay đổi code trên gitHub nhưng trên local Repo của bạn vẫn là code cũ**
  * Dùng lệnh: `git pull` để kéo những thay đổi từ trên gitHub về máy bạn.
- Kiểm tra trạng thái locap Repo để biết:
  * Các thay đổi đã staged (sẵn sàng để commit).
  * Các thay đổi chưa staged (đã thay đổi nhưng chưa được thêm vào staging area).
  * Các file chưa được theo dõi (file mới chưa được thêm vào hệ thống quản lý phiên bản).
  * Dùng lệnh: `git Status`
- Khi muốn bỏ thay đổi trong local Repo (như add file):
  * `git restore --staged + [Tên file]`
- Kiểm tra lịch sử commit trong local Repo:
  * `git log`
- Cách chuyển về file đằng trước/ ra ngoài file:
  * `cd..` hoặc `pwd`
    
