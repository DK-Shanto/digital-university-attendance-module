<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_THESIS.'bao/class.thesisMemberbao.inc';
include_once MODULES_THESIS.'bao/class.thesisbao.inc';

$_ThesisBao=new ThesisBao();
$Thesis=new Thesis();
$_MemberBao=new ThesisMemberBao();
$_DB=DBUtil::getInstance();

/*Add Links*/
if(isset($_GET['id'])&&isset($_POST['add'])){
    $LinkThesis=new LinkThesis();
    $LinkThesis->setLinkThesisId(Util::getGUID());
    $LinkThesis->setThesisId($_GET['id']);
    $LinkThesis->setLink($_DB->secureInput($_POST['link_add']));

    $Result=$_MemberBao->addLink($LinkThesis);

    if($Result->getIsSuccess()){
        echo '<strong>'.$Result->getResultObject().'</strong>';
        header("Location:".PageUtil::$THESIS_MEMBER."?id=".$_GET['id']);
    }
}

/*Add Members*/
if(isset($_GET['auid'])&&isset($_GET['id'])){
    $StudentThesis=new StudentThesis();
    $StudentThesis->setStudentThesisId(Util::getGUID());
    $StudentThesis->setThesisId($_GET['id']);
    $StudentThesis->setStudentId($_GET['auid']);
    $StudentThesis->setContribution($_DB->secureInput(0));

    $Result=$_MemberBao->addMember($StudentThesis);

    if($Result->getIsSuccess()){
        echo '<strong>'.$Result->getResultObject().'</strong>';
        header("Location:".PageUtil::$THESIS_MEMBER."?id=".$_GET['id']);
    }
}

/*Add Supervisors*/
if(isset($_GET['auid2'])&&isset($_GET['id'])){
    $SupervisorThesis=new SupervisorThesis();
    $SupervisorThesis->setSupervisorThesisId(Util::getGUID());
    $SupervisorThesis->setThesisId($_GET['id']);
    $SupervisorThesis->setSupervisorId($_GET['auid2']);

    $Result=$_MemberBao->addSupervisor($SupervisorThesis);

    if($Result->getIsSuccess()){
        echo '<strong>'.$Result->getResultObject().'</strong>';
        header("Location:".PageUtil::$THESIS_MEMBER."?id=".$_GET['id']);
    }
}

/*Remove Links*/
if(isset($_GET['rlid'])&&isset($_GET['id'])){
    $LinkThesis=new LinkThesis();
    $LinkThesis->setThesisId($_GET['id']);
    $LinkThesis->setLinkThesisId($_GET['rlid']);

    $Result=$_MemberBao->removeLink($LinkThesis);

    if($Result->getIsSuccess()){
        echo '<strong>'.$Result->getResultObject().'</strong>';
        header("Location:".PageUtil::$THESIS_MEMBER."?id=".$_GET['id']);
    }
}

/*Remove Members*/
if(isset($_GET['ruid'])&&isset($_GET['id'])){
    $StudentThesis=new StudentThesis();
    $StudentThesis->setThesisId($_GET['id']);
    $StudentThesis->setStudentId($_GET['ruid']);

    $Result=$_MemberBao->removeMember($StudentThesis);

    if($Result->getIsSuccess()){
        echo '<strong>'.$Result->getResultObject().'</strong>';
        header("Location:".PageUtil::$THESIS_MEMBER."?id=".$_GET['id']);
    }
}

/*Remove Supervisors*/
if(isset($_GET['ruid2'])&&isset($_GET['id'])){
    $SupervisorThesis=new SupervisorThesis();
    $SupervisorThesis->setThesisId($_GET['id']);
    $SupervisorThesis->setSupervisorId($_GET['ruid2']);

    $Result=$_MemberBao->removeSupervisor($SupervisorThesis);

    if($Result->getIsSuccess()){
        echo '<strong>'.$Result->getResultObject().'</strong>';
        header("Location:".PageUtil::$THESIS_MEMBER."?id=".$_GET['id']);
    }
}

?>
