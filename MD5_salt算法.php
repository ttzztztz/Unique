<?php //BY YZY 20181023 
function register($user,$password){
    if(isset($_SERVER[$user])) return -1;
    $str = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    for($i=0;$i<4;$i++) //自身复制4次
        $str.=$str;
    $salt = substr(str_shuffle($str),0,8);
    $_SERVER[$user] = array(
        'username'=>$user,
        'salt'=>$salt,
        'password'=>md5(md5($password).$salt)
    );
    return 1;
}
function login($user,$password){
    $password_md5 = md5($password);//这一步加密完成在前端
    if(!isset($_SERVER[$user])) return -1;
    return md5($password_md5.$_SERVER[$user]['salt']) == $_SERVER[$user]['password'];
}
?>