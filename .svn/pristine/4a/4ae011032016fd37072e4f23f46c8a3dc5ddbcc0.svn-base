<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_THESIS.'bao/class.thesisbao.inc';

$_ThesisBao=new ThesisBao();
$_DB=DBUtil::getInstance();

/* saving a new thesis*/
if(isset($_POST['create']))
{
    if (!empty($_POST['title'])&&!empty($_POST['description'])&&!empty($_POST['year_id'])
        &&!empty($_POST['term_id'])&&!empty($_POST['course_id'])&&!empty($_POST['discipline_id'])){

        $Thesis=new Thesis();

        $Thesis->setThesisId(Util::getGUID());
        $Thesis->setThesisTitle($_DB->secureInput($_POST['title']));
        $Thesis->setThesisDescription($_DB->secureInput($_POST['description']));
        $Thesis->setThesisYearId($_POST['year_id']);
        $Thesis->setThesisTermId($_POST['term_id']);
        $Thesis->setThesisCourseId($_POST['course_id']);
        $Thesis->setThesisDisciplineId($_POST['discipline_id']);
        if (!empty($_FILES['report']['name'])) {
            $UploadReport=$_ThesisBao->uploadReport($Thesis);
        }else{
            $UploadReport['uploaded']=1;
            $UploadReport['target_file']="";
        }
        $UploadThumbnail=$_ThesisBao->uploadThumbnail($Thesis);
        //check if the thumbnail has been uploaded
        if($UploadReport['uploaded']==1 && $UploadThumbnail['uploaded']==1){
            $Thesis->setThesisPDFLink($_DB->secureInput($UploadReport['target_file']));
            $Thesis->setThesisThumbnail($_DB->secureInput($UploadThumbnail['target_file']));
            $Result=$_ThesisBao->createThesis($Thesis);

            if($Result->getIsSuccess()){
                echo '<strong>'.$Result->getResultObject().'</strong>';
                header("Location:".PageUtil::$THESIS);
            }
        }
    }
}

/*Edit a thesis*/
if (isset($_GET['edit'])){
    $Thesis=new Thesis();

    $Thesis->setThesisId($_GET['edit']);
    $getRow=$_ThesisBao->getThesis($Thesis)->getResultObject();
}

/*Update a thesis*/
if (isset($_POST['update'])){
    if (!empty($_POST['title'])&&!empty($_POST['description'])&&!empty($_POST['year_id'])
        &&!empty($_POST['term_id'])&&!empty($_POST['course_id'])&&!empty($_POST['discipline_id'])){

        $Thesis=new Thesis();

        $Thesis->setThesisId($_GET['edit']);
        $Thesis->setThesisTitle($_DB->secureInput($_POST['title']));
        $Thesis->setThesisDescription($_DB->secureInput($_POST['description']));
        $Thesis->setThesisYearId($_POST['year_id']);
        $Thesis->setThesisTermId($_POST['term_id']);
        $Thesis->setThesisCourseId($_POST['course_id']);
        $Thesis->setThesisDisciplineId($_POST['discipline_id']);
        $UploadReport=$_ThesisBao->uploadReport($Thesis);
        $UploadThumbnail=$_ThesisBao->uploadThumbnail($Thesis);
        //check if the thumbnail has been uploaded
        if($UploadReport['uploaded']==1 && $UploadThumbnail['uploaded']==1){
            $Thesis->setThesisPDFLink($_DB->secureInput($UploadReport['target_file']));
            $Thesis->setThesisThumbnail($_DB->secureInput($UploadThumbnail['target_file']));
            $Result=$_ThesisBao->updateThesis($Thesis);

            if($Result->getIsSuccess()){
                echo '<strong>'.$Result->getResultObject().'</strong>';
                header("Location:".PageUtil::$THESIS);
            }
        }
    }
}

/*Delete a thesis*/
if (isset($_GET['del'])){
    $Thesis=new Thesis();

    $Thesis->setThesisId($_GET['del']);
    $DeleteReport=$_ThesisBao->deleteReport($_ThesisBao->getThesis($Thesis)->getResultObject());
    $DeleteThumbnail=$_ThesisBao->deleteThumbnail($_ThesisBao->getThesis($Thesis)->getResultObject());
    if ($DeleteReport && $DeleteThumbnail){   
        $Result=$_ThesisBao->deleteThesis($Thesis);

        if ($Result->getIsSuccess()){
            echo '<strong>'.$Result->getResultObject().'</strong>';
            header("Location:".PageUtil::$THESIS);
        }
    }else{
        echo 'Thumbnail cannot be removed';
    }
}

?>
