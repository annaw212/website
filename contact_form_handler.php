<?php
$action=$_REQUEST['action'];
if ($action=="")
    {
    ?>
    <form  action="" method="POST" enctype="multipart/form-data">
    <input type="hidden" name="action" value="submit">
    Your name:<br>
    <input name="name" type="text" value="" size="30"/><br>
    Your email:<br>
    <input name="email" type="text" value="" size="30"/><br>
    Your message:<br>
    <textarea name="message" rows="7" cols="30"></textarea><br>
    <input type="submit" value="Send email"/>
    </form>
    <?php
    } 
else
    {
    $name=$_REQUEST['name'];
    $email=$_REQUEST['email'];
    $subject=$_REQUEST['subject'];
    $message=$_REQUEST['message'];
    if (($name=="")||($email=="")||($subject=="")||($message==""))
        {
        echo "All fields are required.";
        }
    else{        
        $from="From: $name<$email>\r\nReturn-path: $email";
        mail("anna.elise781@gmail.com", $subject, $message, $from);
        echo "Email sent!";
        }
    }  
?>
