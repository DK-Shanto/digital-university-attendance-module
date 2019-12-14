<?php
include_once 'blade/view.sendRepair.blade.inc';
include_once COMMON.'class.common.inc';
?>

<div class="container">
    <!--Heading-->
    <div class="col-md-8 col-md-offset-2">
        <div class="panel myPanel">
            <div class="panel-heading myHeading">
                <strong>&nbsp;Send to Repair</strong>
            </div>
            <div class="panel-body">

                <form method="post" class="form-horizontal">
                    <!--            Serial No-->
                    <div class="form-group">
                        <label for="serialNo" class="control-label col-md-3">Serial No :</label>
                        <div class=" col-md-7">
                            <input type="text" name="serialNo" id="serialNo" class="form-control" onblur="checkSerialJS();" placeholder="Serial No" value="<?php
                            if (isset($_GET['edit'])){
                                $Asset=new Asset();
                                $Asset->setAssetId($getRow->getRepairAssetId());
                                $AssetDetail=$_AssetBao->getAssetById($Asset)->getResultObject();
                                echo $AssetDetail->getAssetSerialNo();
                            }
                            ?>" required>
                            <span id="spnSerialNo" class="text-danger"></span>
                        </div>
                    </div>

                    <!--            Problem-->
                    <div class="form-group">
                        <label for="problem" class="control-label col-md-3">Problem :</label>
                        <div class=" col-md-7">
                        <textarea name="problem" id="problem" rows="5" class="form-control" required><?php
                            if (isset($_GET['edit'])){
                                echo $getRow->getRepairProblem();
                            }
                            ?></textarea>
                        </div>
                    </div>

                    <!--            Sending Date-->
                    <div class="form-group">
                        <label for="sendingDate" class="control-label col-md-3">Sending Date :</label>
                        <div class=" col-md-7">
                            <input type="date" name="sendingDate" id="sendingDate" class="form-control" value="<?php
                            if (isset($_GET['edit'])){
                                echo $getRow->getRepairSendingDate();
                            }
                            ?>" required>
                        </div>
                    </div>

                    <!--            Repaired From-->
                    <div class="form-group">
                        <label for="repairedFrom" class="control-label col-md-3">Sending To :</label>
                        <div class=" col-md-7">
                            <input type="text" name="repairedFrom" id="repairedFrom" class="form-control" placeholder="Repaired From" value="<?php
                            if (isset($_GET['edit'])){
                                echo $getRow->getRepairRepairedFrom();
                            }
                            ?>" required>
                        </div>
                    </div>

                    <!--Button-->
                    <div class="form-group">
                        <?php
                        if (!isset($_GET['edit'])){
                            ?>
                            <input type="submit" id="btnSend" class="btn btn-primary col-md-2 col-md-offset-5" name="send" value="Send">
                            <?php
                        }else{
                            ?>
                            <input type="submit" id="btnUpdate" class="btn btn-primary col-md-2 col-md-offset-5" name="update" value="Update">
                            <?php
                        }
                        ?>
                    </div>
                </form>
            </div>
        </div>
    </div>
</div>
<div class="col-md-12" style="margin-top: -18vh">
    <hr>
</div>
<div class="col-md-12" style="margin-top: -1vh">
    <div class="panel panel-table">
        <table class="table table-bordered table-responsive">
            <!--Header Row-->
            <tr>
                <th>Type</th>
                <th>Serial No</th>
                <th>Model No</th>
                <th>Brand</th>
                <th>Problem</th>
                <th>Sent By</th>
                <th>Sending Date</th>
                <th>Sent To</th>
                <th>On Warranty</th>
                <th>Edit</th>
                <th>Delete</th>
            </tr>

            <!--Table Cells-->
            <?php
            $Result=$_SendRepairBao->getAllRepair();
            if($Result->getIsSuccess()) {
                $RepairList = $Result->getResultObject();
                foreach ($RepairList as $repair) {
                    $Asset=new Asset();
                    $Asset->setAssetId($repair->getRepairAssetId());

                    ?>
                    <tr class="table-cell">
                        <td><?php
                            echo $_AssetBao->getTypeById($_AssetBao->getAssetById($Asset)->getResultObject()->getAssetTypeId())->getResultObject()->getAssetTypeName(); ?>
                        </td>
                        <td>
                            <a href="asset_details.php?serialNo=<?php echo $_AssetBao->getAssetById($Asset)->getResultObject()->getAssetSerialNo(); ?>" class="table-a">
                            <?php echo $_AssetBao->getAssetById($Asset)->getResultObject()->getAssetSerialNo(); ?>
                            </a>
                        </td>
                        <td>
                            <?php echo $_AssetBao->getAssetById($Asset)->getResultObject()->getAssetModelNo(); ?>
                        </td>
                        <td>
                            <?php echo $_AssetBao->getAssetById($Asset)->getResultObject()->getAssetBrand(); ?>
                        </td>
                        <td><?php if (strlen($repair->getRepairProblem())>50){
                                echo substr($repair->getRepairProblem(),0,50).'...';
                            }else{
                                echo $repair->getRepairProblem();
                            } ?>
                        </td>
                        <?php
                        $StuffName=$_AssetBao->getStuffById($repair->getRepairSentBy())->getResultObject();
                        ?>
                        <td><a href="user_details.php?id=<?php echo $StuffName->getID(); ?>" class="table-a"><?php
                                echo $StuffName->getFirstName().' '.$StuffName->getLastName();
                                ?></a>
                        </td>
                        <td>
                            <?php echo $repair->getRepairSendingDate(); ?>
                        </td>
                        <td>
                            <?php echo $repair->getRepairRepairedFrom(); ?>
                        </td>
                        <td <?php if ($repair->getRepairOnWarranty()){
                            echo 'class="text-success"';
                        }else{
                            echo 'class="text-danger"';
                        }
                        ?>>
                            <?php if ($repair->getRepairOnWarranty()){
                                echo 'Yes';
                            }else{
                                echo 'No';
                            } ?>
                        </td>
                        <td><a href="?edit=<?php echo $repair->getRepairId(); ?>"
                               onclick="return confirm('sure to edit !!');">edit</a></td>

                        <td><a href="?del=<?php echo $repair->getRepairId(); ?>"
                               class="span-danger"
                               onclick="return confirm('sure to delete !!');">delete</a></td>
                    </tr>
                    <?php
                }
            }
            ?>
        </table>
    </div>
</div>


<script>
    function checkSerialJS() {
        var serial=$('#serialNo').val();
        $.ajax({
           url:"./modules/assetArchive/ui/checkSendSerial.php",
           type:"get",
           data:{val:serial},
           success:function (data) {
               $('#spnSerialNo').text(data);
               if(data==""){
                   $('#btnSend').prop('disabled',false);
                   $('#btnUpdate').prop('disabled',false);
               }else{
                   $('#btnSend').prop('disabled',true);
                   $('#btnUpdate').prop('disabled',true);
               }
           },
           error:function (data) {

           }
        });
    }
</script>
