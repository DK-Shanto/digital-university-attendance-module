<!--Email CRUD-->
<?php
// write dao object for each class
include_once COMMON.'class.common.email.inc';
include_once UTILITY.'class.util.inc';

Class EmailDao
{
    private $_DB;
    private $_Email;

    function __construct()
    {
        $this->_Email=new Email();
        $this->_DB = DBUtil::getInstance();
    }

    //get All email
    public function getAllEmail(){
        $EmailList=array();

        $SQL="SELECT * FROM ems_email ORDER BY ems_email.created_at";
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

    //create new email
    public function createEmail($Email){

        $ID=$Email->getEmailId();
        $FirstName=$Email->getEmailFirstName();
        $LastName=$Email->getEmailLastName();
        $Mail=$Email->getEmailEmail();
        $Contact=$Email->getEmailContact();
        $ContactEmail=$Email->getEmailContactEmail();
        $Address=$Email->getEmailAddress();
        $CreatedAt=$Email->getEmailCreatedAt();
        $ExpireAt=$Email->getEmailExpireAt();

        $SQL = "INSERT INTO ems_email VALUES('$ID','$FirstName','$LastName','$Mail','$Contact','$ContactEmail','$Address','$CreatedAt','$ExpireAt')";

        $SQL = $this->_DB->doQuery($SQL);

        $Result = new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }

    //get specific email
    public function getEmail($Email){

        $SQL="SELECT * FROM ems_email WHERE ems_email.id='".$Email->getEmailId()."'";
        $this->_DB->doQuery($SQL);

        $row=$this->_DB->getTopRow();
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

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Email);

        return $Result;
    }

    //update previous email
    public function updateEmail($Email){
        $SQL="UPDATE ems_email SET ems_email.firstName='".$Email->getEmailFirstName()."', ems_email.lastName='".$Email->getEmailLastName()."',ems_email.email='".$Email->getEmailEmail()."',
        ems_email.contact='".$Email->getEmailContact()."',ems_email.contactEmail='".$Email->getEmailContactEmail()."',
        ems_email.address='".$Email->getEmailAddress()."',ems_email.created_at='".$Email->getEmailCreatedAt()."',
        ems_email.expire_at='".$Email->getEmailExpireAt()."' WHERE ems_email.id='".$Email->getEmailId()."'";

        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }

    //delete specific email
    public function deleteEmail($Email){
        $SQL="DELETE FROM ems_email WHERE ems_email.id='".$Email->getEmailId()."'";
        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }

}
