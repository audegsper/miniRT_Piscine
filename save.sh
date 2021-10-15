cp -r * ../backup/
git add *
echo -e "git commit -m에 넣을 메세지를 넣어주세요."
read  msg
git commit -m "$msg"
git push https://github.com/audegsper/miniRT_Piscine.git
