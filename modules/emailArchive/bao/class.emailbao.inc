<!--Email CRUD-->
<?php
include_once UTILITY.'class.util.inc';
include_once MODULES_EMAIL.'dao/class.emaildao.inc';

/*
	User Business Object
*/
Class EmailBao
{

    private $_EmailDao;

    function __construct()
    {
        $this->_EmailDao=new EmailDao();
    }

    //get All Email
    public function getAllEmail(){

        $Result=$this->_EmailDao->getAllEmail();

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in EmailDao.getAllEmail()");
        }

        return $Result;
    }

    //new Email Record creation
    public function createEmail($Email){

        $Result = $this->_EmailDao->createEmail($Email);

        if(!$Result->getIsSuccess())
            $Result->setResultObject("Database failure in EmailDao.createEmail($Email)");

        return $Result;
    }

    //get specific email
    public function getEmail($Email){
        $Result=$this->_EmailDao->getEmail($Email);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in EmailDao.getEmail($Email)");
        }
        return $Result;
    }
    //update previous email
    public function updateEmail($Email){
        $Result=$this->_EmailDao->updateEmail($Email);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in EmailDao.updateEmail($Email)");
        }
        return $Result;
    }

    //delete specific email
    public function deleteEmail($Email){
        $Result=$this->_EmailDao->deleteEmail($Email);

        if(!$Result->getIsSuccess()){
            $Result->setResultObject("Database failure in EmailDao.deleteEmail($Email)");
        }
        return $Result;
    }
}