<!--Thesis CRUD-->
<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_THESIS.'dao/class.thesisdao.inc';

/*
	User Business Object
*/
Class ThesisBao
{

    private $_ThesisDao;

    function __construct()
    {

        $this->_ThesisDao = new ThesisDao();

    }

    //new Thesis creation
    public function createThesis($Thesis){

        $Result = $this->_ThesisDao->createThesis($Thesis);

        if(!$Result->getIsSuccess())
            $Result->setResultObject("Database failure in ThesisDao.newThesis()");

        return $Result;
    }

     //upload thesis report
    public function uploadReport($Thesis){
        $Upload=$this->_ThesisDao->uploadReport($Thesis);

        return $Upload;
    }

    //delete thesis report
    public function deleteReport($Thesis){
        $Delete=$this->_ThesisDao->deleteReport($Thesis);

        return $Delete;
    }

    //upload thesis thumbnails
    public function uploadThumbnail($Thesis){
        $Upload=$this->_ThesisDao->uploadThumbnail($Thesis);

        return $Upload;
    }

    //delete thesis thumbnail
    public function deleteThumbnail($Thesis){
        $Delete=$this->_ThesisDao->deleteThumbnail($Thesis);

        return $Delete;
    }

    //get All Thesiss
    public function getAllThesis(){

        $Result=$this->_ThesisDao->getAllThesis();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisDao.getAllThesis()");
        }

        return $Result;
    }

    //get All Years
    public function getAllYears(){
        $Result=$this->_ThesisDao->getAllYears();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisDao.getAllYears()");
        }

        return $Result;
    }

    //get All Terms
    public function getAllTerms(){
        $Result=$this->_ThesisDao->getAllTerms();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisDao.getAllTerms()");
        }

        return $Result;
    }

    //get All Courses
    public function getAllCourses(){
        $Result=$this->_ThesisDao->getAllCourses();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisDao.getAllCourses()");
        }

        return $Result;
    }

    //get All Disciplines
    public function getAllDisciplines(){
        $Result=$this->_ThesisDao->getAllDisciplines();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisDao.getAllDisciplines()");
        }

        return $Result;
    }

     //get All Teachers
    public function getAllTeachers(){
        $Result=$this->_ThesisDao->getAllTeachers();
        
        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisDao.getAllTeachers()");
        }
        return $Result;
    }

    //get specific year
    public function getYear($Year){
        $Result=$this->_ThesisDao->getYear($Year);
        
        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisDao.getYear($Year)");
        }
        return $Result;
    }

    //get specific Term
    public function getTerm($Term){
        $Result=$this->_ThesisDao->getTerm($Term);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisDao.getTerm($Term)");
        }
        return $Result;
    }

    //get specific course
    public function getCourse($Course){
        $Result=$this->_ThesisDao->getCourse($Course);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisDao.getCourse($Course)");
        }
        return $Result;
    }

    //get specific discipline
    public function getDiscipline($Discipline){
        $Result=$this->_ThesisDao->getDiscipline($Discipline);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisDao.getDiscipline($Discipline)");
        }
        return $Result;
    }

    //get specific teacher
    public function getTeacher($Teacher){
        $Result=$this->_ThesisDao->getTeacher($Teacher);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisDao.getTeacher($Teacher)");
        }
        return $Result;
    }

    //get specific thesis
    public function getThesis($Thesis){
        $Result=$this->_ThesisDao->getThesis($Thesis);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisDao.getThesis($Thesis)");
        }
        return $Result;
    }
    
    //update previous thesis
    public function updateThesis($Thesis){
        $Result=$this->_ThesisDao->updateThesis($Thesis);
        
        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisDao.updateThesis($Thesis)");
        }
        return $Result;
    }

    //delete specific thesis
    public function deleteThesis($Thesis){
        $Result=$this->_ThesisDao->deleteThesis($Thesis);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ThesisDao.deleteThesis($Thesis)");
        }
        return $Result;
    }

}
?>
