<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_PROJECT.'bao/class.projectMemberbao.inc';
include_once MODULES_PROJECT.'bao/class.projectbao.inc';

$_ProjectBao=new ProjectBao();
$Project=new Project();
$_MemberBao=new ProjectMemberBao();
$_DB=DBUtil::getInstance();

/*Add Link*/
if (isset($_POST['add'])){
    $LinkProject=new LinkProject();
    $LinkProject->setLinkProjectId(Util::getGUID());
    $LinkProject->setLink($_DB->secureInput($_POST['link_add']));
    $LinkProject->setProjectId($_GET['id']);

    $Result=$_MemberBao->addLink($LinkProject);

    if ($Result->getIsSuccess()){
        echo '<strong>'.$Result->getResultObject().'</strong>';
        header("Location:".PageUtil::$PROJECT_MEMBER."?id=".$_GET['id']);
    }
}

/*Remove Links*/
if(isset($_GET['rlid'])&&isset($_GET['id'])){
    $LinkProject=new LinkProject();
    $LinkProject->setProjectId($_GET['id']);
    $LinkProject->setLinkProjectId($_GET['rlid']);

    $Result=$_MemberBao->removeLink($LinkProject);

    if($Result->getIsSuccess()){
        echo '<strong>'.$Result->getResultObject().'</strong>';
        header("Location:".PageUtil::$PROJECT_MEMBER."?id=".$_GET['id']);
    }
}


/*Add Members*/
if(isset($_GET['auid'])&&isset($_GET['id'])){
    $StudentProject=new StudentProject();
    $StudentProject->setStudentProjectId(Util::getGUID());
    $StudentProject->setProjectId($_GET['id']);
    $StudentProject->setStudentId($_GET['auid']);
    $StudentProject->setContribution($_DB->secureInput(0));

    $Result=$_MemberBao->addMember($StudentProject);

    if($Result->getIsSuccess()){
        echo '<strong>'.$Result->getResultObject().'</strong>';
        header("Location:".PageUtil::$PROJECT_MEMBER."?id=".$_GET['id']);
    }
}

/*Remove Members*/
if(isset($_GET['ruid'])&&isset($_GET['id'])){
    $StudentProject=new StudentProject();
    $StudentProject->setProjectId($_GET['id']);
    $StudentProject->setStudentId($_GET['ruid']);

    $Result=$_MemberBao->removeMember($StudentProject);

    if($Result->getIsSuccess()){
        echo '<strong>'.$Result->getResultObject().'</strong>';
        header("Location:".PageUtil::$PROJECT_MEMBER."?id=".$_GET['id']);
    }
}

?>
