<!--Assign or remove members to a project-->
<?php
// write dao object for each class
include_once COMMON.'class.common.project.inc';
include_once UTILITY.'class.util.inc';

class ProjectMemberDao{
    private $_DB;
    private $_StudentProject;
    private $_LinkProject;
    private $_Student;

    public function __construct()
    {
        $this->_DB=DBUtil::getInstance();
        $this->_StudentProject=new StudentProject();
        $this->_LinkProject=new LinkProject();
        $this->_Student=new User();
    }

    public function addLink($LinkProject){
        $ID=$LinkProject->getLinkProjectId();
        $Link=$LinkProject->getLink();
        $ProjectId=$LinkProject->getProjectId();

        $SQL="INSERT INTO pms_link_project VALUES('$ID','$Link','$ProjectId')";
        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }

    public function addMember($StudentProject){
        $ID=$StudentProject->getStudentProjectId();
        $ProjectId=$StudentProject->getProjectId();
        $StudentId=$StudentProject->getStudentId();
        $Contribution=$StudentProject->getContribution();

        $SQL="INSERT INTO pms_student_project VALUES ('$ID','$StudentId','$ProjectId','$Contribution')";
        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }

    public function getLink($Project){
        $LinkList=array();
        $SQL="SELECT * FROM pms_link_project WHERE pms_link_project.project_id='".$Project->getProjectId()."'";
        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();
        foreach ($rows as $row) {
            $this->_LinkProject=new LinkProject();
            $this->_LinkProject->setLinkProjectId($row['id']);
            $this->_LinkProject->setLink($row['link']);
            $this->_LinkProject->setProjectId($row['project_id']);

            $LinkList[]=$this->_LinkProject;
        }

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($LinkList);

        return $Result;
    }

    public function getMember($Project){
        $MemberList=array();
        $SQL="SELECT * FROM pms_student_project WHERE pms_student_project.project_id='".$Project->getProjectId()."'";
        $this->_DB->doQuery($SQL);

        $rows=$this->_DB->getAllRows();
        foreach ($rows as $row) {
            $this->_StudentProject=new StudentProject();
            $this->_StudentProject->setStudentProjectId($row['id']);
            $this->_StudentProject->setStudentId($row['student_id']);
            $this->_StudentProject->setProjectId($row['project_id']);
            $this->_StudentProject->setContribution($row['contribution']);

            $MemberList[]=$this->_StudentProject;
        }

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($MemberList);

        return $Result;
    }

    public function getStudent($Student){
        $SQL="SELECT ums_user.ID,ums_user.Email,ums_user.FirstName,ums_user.LastName FROM ums_user WHERE ums_user.ID='".$Student."'";
        $this->_DB->doQuery($SQL);
        $row=$this->_DB->getTopRow();
        $this->_Student=new User();
        $this->_Student->setID($row['ID']);
        $this->_Student->setEmail($row['Email']);
        $this->_Student->setFirstName($row['FirstName']);
        $this->_Student->setLastName($row['LastName']);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Student);

        return $Result;
    }

    public function removeLink($Link){
        $SQL="DELETE FROM pms_link_project WHERE pms_link_project.project_id='".$Link->getProjectId()."' 
        AND pms_link_project.id='".$Link->getLinkProjectId()."'";

        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }

    public function removeMember($Student){
        $SQL="DELETE FROM pms_student_project WHERE pms_student_project.project_id='".$Student->getProjectId()."' 
        AND pms_student_project.student_id='".$Student->getStudentId()."'";

        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }

}
?>
