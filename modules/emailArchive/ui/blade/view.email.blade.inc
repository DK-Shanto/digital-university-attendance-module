<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_EMAIL.'bao/class.emailbao.inc';

$_EmailBao=new EmailBao();
$_DB=DBUtil::getInstance();

/* saving a new email record*/
if(isset($_POST['create']))
{
    if (!empty($_POST['firstName'])&&!empty($_POST['lastName'])&&!empty($_POST['email'])
        &&!empty($_POST['contact'])&&!empty($_POST['contactEmail'])&&!empty($_POST['address'])&&!empty($_POST['createdAt'])
        &&!empty($_POST['expireAt'])){

        $Email=new Email();

        $Email->setEmailId(Util::getGUID());
        $Email->setEmailFirstName($_DB->secureInput($_POST['firstName']));
        $Email->setEmailLastName($_DB->secureInput($_POST['lastName']));
        $Email->setEmailEmail($_DB->secureInput($_POST['email']));
        $Email->setEmailContact($_DB->secureInput($_POST['contact']));
        $Email->setEmailContactEmail($_DB->secureInput($_POST['contactEmail']));
        $Email->setEmailAddress($_DB->secureInput($_POST['address']));
        $Email->setEmailCreatedAt($_DB->secureInput($_POST['createdAt']));
        $Email->setEmailExpireAt($_DB->secureInput($_POST['expireAt']));

        $Result=$_EmailBao->createEmail($Email);

        if($Result->getIsSuccess()){
            echo '<strong>'.$Result->getResultObject().'</strong>';
            header("Location:".PageUtil::$EMAIL);
        }
    }
}

/*Edit a email record*/
if (isset($_GET['edit'])){
    $Email=new Email();

    $Email->setEmailId($_GET['edit']);
    $getRow=$_EmailBao->getEmail($Email)->getResultObject();
}

/*Update a email record*/
if (isset($_POST['update'])){
    if (!empty($_POST['firstName'])&&!empty($_POST['lastName'])&&!empty($_POST['email'])
        &&!empty($_POST['contact'])&&!empty($_POST['contactEmail'])&&!empty($_POST['address'])&&!empty($_POST['createdAt'])
        &&!empty($_POST['expireAt'])){

        $Email=new Email();

        $Email->setEmailId($_GET['edit']);
        $Email->setEmailFirstName($_DB->secureInput($_POST['firstName']));
        $Email->setEmailLastName($_DB->secureInput($_POST['lastName']));
        $Email->setEmailEmail($_DB->secureInput($_POST['email']));
        $Email->setEmailContact($_DB->secureInput($_POST['contact']));
        $Email->setEmailContactEmail($_DB->secureInput($_POST['contactEmail']));
        $Email->setEmailAddress($_DB->secureInput($_POST['address']));
        $Email->setEmailCreatedAt($_DB->secureInput($_POST['createdAt']));
        $Email->setEmailExpireAt($_DB->secureInput($_POST['expireAt']));

        $Result=$_EmailBao->updateEmail($Email);

        if($Result->getIsSuccess()){
            echo '<strong>'.$Result->getResultObject().'</strong>';
            header("Location:".PageUtil::$EMAIL);
        }
    }
}

/*Delete a email record*/
if (isset($_GET['del'])){
    $Email=new Email();

    $Email->setEmailId($_GET['del']);

    $Result=$_EmailBao->deleteEmail($Email);

    if ($Result->getIsSuccess()){
        echo '<strong>'.$Result->getResultObject().'</strong>';
        header("Location:".PageUtil::$EMAIL);
    }
}

?>
