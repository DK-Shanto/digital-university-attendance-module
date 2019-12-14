<!--Email CRUD-->
<?php
// write dao object for each class
include_once COMMON.'class.common.email.inc';
include_once UTILITY.'class.util.inc';

Class EmailRenewDao
{
    private $_DB;
    private $_Email;

    function __construct()
    {
        $this->_Email = new Email();
        $this->_DB = DBUtil::getInstance();
    }

    //get paginated emails
    public function getLimitEmail($page,$limit){
        $EmailList=array();

        $SQL="SELECT * FROM ems_email ORDER BY ems_email.created_at LIMIT $page,$limit";
        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();

        foreach ($rows as $row) {
            $this->_Email=new Email();
            $this->_Email->setEmailId($row['id']);
            $this->_Email->setEmailFirstName($row['firstName']);
            $this->_Email->setEmailLastName($row['lastName']);
            $this->_Email->setEmailEmail($row['email']);
            $this->_Email->setEmailContact($row['contact']);
            $this->_Email->setEmailContactEmail($row['contactEmail']);
            $this->_Email->setEmailAddress($row['address']);
            $this->_Email->setEmailCreatedAt($row['created_at']);
            $this->_Email->setEmailExpireAt($row['expire_at']);

            $EmailList[]=$this->_Email;
        }

        //todo: LOG util with level of log

        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($EmailList);

        return $Result;
    }

    //get renew email
    public function getRenewEmail(){
        $EmailList=array();

        $SQL="SELECT * FROM ems_email WHERE ems_email.expire_at-ems_email.created_at>-1 ORDER BY ems_email.created_at";
        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();

        foreach ($rows as $row) {
            $this->_Email=new Email();
            $this->_Email->setEmailId($row['id']);
            $this->_Email->setEmailFirstName($row['firstName']);
            $this->_Email->setEmailLastName($row['lastName']);
            $this->_Email->setEmailEmail($row['email']);
            $this->_Email->setEmailContact($row['contact']);
            $this->_Email->setEmailContactEmail($row['contactEmail']);
            $this->_Email->setEmailAddress($row['address']);
            $this->_Email->setEmailCreatedAt($row['created_at']);
            $this->_Email->setEmailExpireAt($row['expire_at']);

            $EmailList[]=$this->_Email;
        }

        //todo: LOG util with level of log


        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($EmailList);

        return $Result;

    }
}