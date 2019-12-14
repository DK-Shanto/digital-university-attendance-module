<?php
// write dao object for each class
include_once COMMON.'class.common.asset.inc';
include_once UTILITY.'class.util.inc';

Class ReceiveRepairDao
{

    private $_DB;
    private $_Asset;
    private $_Repair;

    function __construct()
    {
        $this->_DB = DBUtil::getInstance();
        $this->_Asset = new Asset();
        $this->_Repair = new Repair();
    }

    public function getRepairByAssetSerialNo($Asset){
        $SQL="SELECT * FROM ams_asset WHERE ams_asset.serialNo='$Asset'";
        $this->_DB->doQuery($SQL);
        $row=$this->_DB->getTopRow();

        $SQL="SELECT * FROM ams_repair WHERE ams_repair.asset_id='".$row['id']."' AND ams_repair.isReceived=0";
        $this->_DB->doQuery($SQL);

        $row=$this->_DB->getTopRow($SQL);

        $this->_Repair=new Repair();
        $this->_Repair->setRepairId($row['id']);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Repair);

        return $Result;
    }

    public function receiveRepair($Repair){
        $SQL="UPDATE ams_repair SET ams_repair.receivingDate='".$Repair->getRepairReceivingDate()."',ams_repair.status='".$Repair->getRepairStatus()."',
        ams_repair.received_by='".$Repair->getRepairReceivedBy()."',ams_repair.cost='".$Repair->getRepairCost()."',ams_repair.isReceived='".$Repair->getRepairIsReceived()."'
        WHERE ams_repair.id='".$Repair->getRepairId()."'";

        $SQL=$this->_DB->doQuery($SQL);

        if ($Repair->getRepairStatus()=="Repaired"||$Repair->getRepairStatus()=="Partially Repaired"){
            $SQL2="UPDATE ams_asset SET ams_asset.status='Working' WHERE ams_asset.id='".$Repair->getRepairAssetId()."'";
            $SQL2=$this->_DB->doQuery($SQL2);
        }else{
            $SQL2="UPDATE ams_asset SET ams_asset.status='Damaged' WHERE ams_asset.id='".$Repair->getRepairAssetId()."'";
            $SQL2=$this->_DB->doQuery($SQL2);
        }


        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL*$SQL2);

        return $Result;
    }

    public function getAllRepair(){
        $RepairList=array();

        $SQL="SELECT * FROM ams_repair WHERE ams_repair.isReceived=1 ORDER BY ams_repair.receivingDate";
        $this->_DB->doQuery($SQL);
        $rows=$this->_DB->getAllRows();

        foreach ($rows as $row) {
            $this->_Repair=new Repair();
            $this->_Repair->setRepairId($row['id']);
            $this->_Repair->setRepairAssetId($row['asset_id']);
            $this->_Repair->setRepairProblem($row['problem']);
            $this->_Repair->setRepairSendingDate($row['sendingDate']);
            $this->_Repair->setRepairReceivingDate($row['receivingDate']);
            $this->_Repair->setRepairStatus($row['status']);
            $this->_Repair->setRepairSentBy($row['sent_by']);
            $this->_Repair->setRepairReceivedBy($row['received_by']);
            $this->_Repair->setRepairRepairedFrom($row['repaired_from']);
            $this->_Repair->setRepairCost($row['cost']);
            $this->_Repair->setRepairOnWarranty($row['onWarranty']);

            $RepairList[]=$this->_Repair;
        }

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($RepairList);

        return $Result;
    }

    public function getRepairById($Repair){
        $SQL="SELECT * FROM ams_repair WHERE ams_repair.id='$Repair'";
        $this->_DB->doQuery($SQL);
        $row=$this->_DB->getTopRow();

        $this->_Repair=new Repair();
        $this->_Repair->setRepairId($row['id']);
        $this->_Repair->setRepairAssetId($row['asset_id']);
        $this->_Repair->setRepairReceivingDate($row['receivingDate']);
        $this->_Repair->setRepairStatus($row['status']);
        $this->_Repair->setRepairCost($row['cost']);
        $this->_Repair->setRepairOnWarranty($row['onWarranty']);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($this->_Repair);

        return $Result;
    }

    public function updateRepair($Repair){
        $SQL="UPDATE ams_repair SET ams_repair.asset_id='".$Repair->getRepairAssetId()."',ams_repair.receivingDate='".$Repair->getRepairReceivingDate()."',
        ams_repair.status='".$Repair->getRepairStatus()."',ams_repair.received_by='".$Repair->getRepairReceivedBy()."',
        ams_repair.cost='".$Repair->getRepairCost()."',ams_repair.isReceived='".$Repair->getRepairIsReceived()."' WHERE ams_repair.id='".$Repair->getRepairId()."'";

        $SQL=$this->_DB->doQuery($SQL);

        if ($Repair->getRepairStatus()=="Repaired"||$Repair->getRepairStatus()=="Partially Repaired"){
            $SQL2="UPDATE ams_asset SET ams_asset.status='Working' WHERE ams_asset.id='".$Repair->getRepairAssetId()."'";
            $SQL2=$this->_DB->doQuery($SQL2);
        }else{
            $SQL2="UPDATE ams_asset SET ams_asset.status='Damaged' WHERE ams_asset.id='".$Repair->getRepairAssetId()."'";
            $SQL2=$this->_DB->doQuery($SQL2);
        }

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL*$SQL2);

        return $Result;
    }

    public function deleteRepair($Repair){
        $SQL="DELETE FROM ams_repair WHERE ams_repair.id='$Repair'";
        $SQL=$this->_DB->doQuery($SQL);

        $Result=new Result();
        $Result->setIsSuccess(1);
        $Result->setResultObject($SQL);

        return $Result;
    }

}