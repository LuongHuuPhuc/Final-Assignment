# **Final Assignment**
*** 
*Hệ Thống Quản Lý Phân Công Giảng Dạy Cho Giáo Viên*

```cpp bash
std::cout << "教師の授業割り当て管理システム" << std::endl;
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
  * `git push origin <master>` (\<master> là tên nhánh- brach chính của remote Repo) (Ngoài ra sau khi commit file xong thì dùng lệnh này để push lên remote Repo)
  * `git pull origin <master>`
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
  * Dùng lệnh: `git status`
- Khi muốn bỏ thay đổi trong local Repo (như add file):
  * `git restore --staged + [Tên file]`
  * `git checkout -- [file]` (Hủy các thay đổi chưa được commit)
- Kiểm tra lịch sử commit trong local Repo:
  * `git log`
- Cách chuyển về file đằng trước/ ra ngoài file:
  * `cd..` hoặc `pwd`
- Cách xóa file trong Remote Repo từ git bash:
  * `git rm + [Tên file]`
    > Xóa xong nhớ dùng lệnh `git commit -m` để xác nhận và `git push` để up lại lên remote Repo
- Clone tất cả các file từ gitHub về máy:
  * `git clone + [URL gitHub]`
- Check sự khác nhau 2 lần commit:
  * `git diff commit1 commit2` trong đó commit1 và commit2 là 2 hash của commit mà ta cần so sánh. Nếu muốn kiểm tra trong 1 file cụ thể: `git diff commit1 commit2 -- file.txt`
  * Kiểm tra sự khác nhau giữa commit hiện tại và commit trước đó: `git diff HEAD^`
*** 
## **Hợp nhất các Branch lại với nhau** ##
1. Trước khi chuyển đổi luôn kiểm tra 2 nhánh bằng `git checkout + [Nhánh]` và `git pull origin + [Nhánh]` để đảm bảo chúng được cập nhật mới nhất từ Remote repo.
2. Chuyển đổi giữa các nhánh/ brach trong Repo:
  * `git checkout + [branch]`
    > Ví dụ: muốn hợp nhất 'master' về 'main', trước đó hãy chuyển về nhánh 'main'
    > `git checkout main`
3. Hợp nhất 2 nhánh với nhau:
  * `git merge + [tên nhánh gộm]`
    > Ví dụ: gộp nhánh 'master' vào 'main': `git merge master`
> Giải quyết xung đột (Nếu có):
  * Trong quá trình hợp nhất, có thể xảy ra xung đột nếu cùng một phần của cùng một tệp được thay đổi khác nhau trong cả hai nhánh. Git sẽ thông báo cho bạn biết tệp nào gặp xung đột và yêu cầu bạn giải quyết, khi đó cần dùng lệnh `git add + [Tên file xung đột]` + `git commit -m ".."` để update lại file.
4. Sau đó push lên Remote repo bằng lệnh: `git push origin + [Nhánh hợp nhất]`
### Lưu ý: thông thường 2 nhánh khác nhau vì không chung lịch sử commit nên thường hiện ra lỗi: "fatal: refusing to merge unrelated histories" ###
***Cách giải quyết:***
- Dùng lệnh: `git merge + [Nhánh hợp nhất] --allow-unrelated-histories` để bỏ qua các lịch sử commit không liên quan.
***
- Xem danh sách Branch: `git branch`
- Tạo Branch mới: `git branch + tên branch`
- Xóa Branch `git branch -d + tên branch`
- Đổi tên nhánh `git branch -m (branch cũ) (branch mới)`
## **Xóa branch bất kỳ bằng git bash** ##
* Trước tiên phải chắc chắn rằng bạn đang không ở branch mà bạn muốn xóa, trước hết hãy chuyển sang 1 branch khác bằng lệnh `git checkout + branch`
* Sau đó để xóa branch ra khỏi local Repo, dùng lệnh: `git branch -d + [tên Branch]`. **-D** thay vì **-d** nếu nhánh chưa được hợp nhất.
* Xóa nhánh từ remote Repo (gitHub): Bạn cần đẩy lệnh xóa nhánh lên bằng lệnh:  `git push origin --delete + [tên Branch]`

### **File .gitignore** ###
* Đây là một file giúp bạn bỏ qua các file hay thư mục mà bạn không muốn push lên github
**Tạo file .gitignore trên gitBash**
  1. Mở terminal hay gitBash lên, sau đó dùng lệnh `touch` + tên file, ở dây là .gitignore để tạo file
  2. Mở file .gitignore để chỉnh sửa bằng cú pháp `nano` + tên file
  > Muốn bỏ qua file thì gõ `*`+ .định_dạng, bỏ qua folder thì `tên_folder` + "/"
* Bạn cần thêm và commit file .gitignore vào remote Repo của mình:
  `git add .gitignore`
  `git commit -m` + "Text"
  ## **Lưu Ý** ##
  * `git checkout <branch>` chỉ chuyển bạn sang branch đã có trong local repository, và không tự động cập nhật nội dung từ remote (nội dung cũ và nó là local repo)
  * Nếu bạn muốn cập nhật branch local từ remote repository, bạn cần chạy lệnh `git pull` sau khi checkout.
  * Nếu chưa cập nhật (pull), bạn sẽ chỉ thấy các file và nội dung từ lần cuối bạn làm việc với local branch.
 
