<!--Project CRUD-->
<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_PROJECT.'dao/class.projectdao.inc';

/*
	User Business Object
*/
Class ProjectBao
{

    private $_ProjectDao;

    function __construct()
    {

        $this->_ProjectDao = new ProjectDao();

    }

    //new Project creation
    public function createProject($Project){

        $Result = $this->_ProjectDao->createProject($Project);

        if(!$Result->getIsSuccess())
            $Result->setResultObject("Database failure in ProjectDao.newProject()");

        return $Result;
    }

    //upload project thumbnails
    public function uploadThumbnail($Project){
        $Upload=$this->_ProjectDao->uploadThumbnail($Project);

        return $Upload;
    }

    //delete project thumbnail
    public function deleteThumbnail($Project){
        $Delete=$this->_ProjectDao->deleteThumbnail($Project);

        return $Delete;
    }

    //get All Projects
    public function getAllProjects(){

        $Result=$this->_ProjectDao->getAllProjects();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ProjectDao.getAllProject()");
        }

        return $Result;
    }

    //get All Years
    public function getAllYears(){
        $Result=$this->_ProjectDao->getAllYears();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ProjectDao.getAllYears()");
        }

        return $Result;
    }

    //get All Terms
    public function getAllTerms(){
        $Result=$this->_ProjectDao->getAllTerms();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ProjectDao.getAllTerms()");
        }

        return $Result;
    }

    //get All Courses
    public function getAllCourses(){
        $Result=$this->_ProjectDao->getAllCourses();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ProjectDao.getAllCourses()");
        }

        return $Result;
    }

    //get All Disciplines
    public function getAllDisciplines(){
        $Result=$this->_ProjectDao->getAllDisciplines();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ProjectDao.getAllDisciplines()");
        }

        return $Result;
    }

    //get All Teachers
    public function getAllTeachers(){
        $Result=$this->_ProjectDao->getAllTeachers();
        
        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ProjectDao.getAllTeachers()");
        }
        return $Result;
    }

    //get specific year
    public function getYear($Year){
        $Result=$this->_ProjectDao->getYear($Year);
        
        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ProjectDao.getYear($Year)");
        }
        return $Result;
    }

    //get specific Term
    public function getTerm($Term){
        $Result=$this->_ProjectDao->getTerm($Term);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ProjectDao.getTerm($Term)");
        }
        return $Result;
    }

    //get specific course
    public function getCourse($Course){
        $Result=$this->_ProjectDao->getCourse($Course);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ProjectDao.getCourse($Course)");
        }
        return $Result;
    }

    //get specific discipline
    public function getDiscipline($Discipline){
        $Result=$this->_ProjectDao->getDiscipline($Discipline);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ProjectDao.getDiscipline($Discipline)");
        }
        return $Result;
    }

    //get specific teacher
    public function getTeacher($Teacher){
        $Result=$this->_ProjectDao->getTeacher($Teacher);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ProjectDao.getTeacher($Teacher)");
        }
        return $Result;
    }

    //get specific project
    public function getProject($Project){
        $Result=$this->_ProjectDao->getProject($Project);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ProjectDao.getProject($Project)");
        }
        return $Result;
    }
    
    //update previous project
    public function updateProject($Project){
        $Result=$this->_ProjectDao->updateProject($Project);
        
        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ProjectDao.updateProject($Project)");
        }
        return $Result;
    }

    //delete specific project
    public function deleteProject($Project){
        $Result=$this->_ProjectDao->deleteProject($Project);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in ProjectDao.deleteProject($Project)");
        }
        return $Result;
    }

}
?>
