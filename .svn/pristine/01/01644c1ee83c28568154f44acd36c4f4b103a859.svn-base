<!--Search specific project-->
<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_PROJECT.'dao/class.searchProjectdao.inc';

/*
	User Business Object
*/
Class SearchProjectBao
{

    private $_SearchProjectDao;

    public function __construct()
    {
        $this->_SearchProjectDao=new SearchProjectDao();
    }

    //get All Languages
    public function getAllLanguages(){
        $Result=$this->_SearchProjectDao->getAllLanguages();
        
        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in SearchProjectDao.getAllLanguages()");
        }
        return $Result;
    }   

    //get searched project
    public function getSearchedProject(){
        $Result=$this->_SearchProjectDao->getSearchedProject();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in SearchProjectDao.getSearchedProject()");
        }
        return $Result;
    }
    
    //get all students
    public function getAllStudents(){
        $Result=$this->_SearchProjectDao->getAllStudents();
        
        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in SearchProjectDao.getAllStudents()");
        }
        return $Result;
    }   
    
}
?>
