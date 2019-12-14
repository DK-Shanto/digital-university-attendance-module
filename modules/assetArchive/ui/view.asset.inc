<?php
include_once 'blade/view.asset.blade.inc';
include_once COMMON.'class.common.inc';
?>

<div class="container">
    <div class="tab myPanel">
    
      
    </div>

    <!--Asset-->
    <div id="Asset" class="tabcontent myPanel col-md-12">
        <br>
        <div class="col-md-8 col-md-offset-2">
            <div class="panel myPanel">
                <div class="panel-heading myHeading">
                    <strong>&nbsp;Add Asset</strong>
                </div>
                <div class="panel-body">
                    <form class="form-horizontal" method="post">
                        <!--Type-->
                        <div class="form-group">
                            <label for="typeDDL" class="col-md-3 control-label">Type :</label>
                            <div class="col-md-7">
                                <div id="divTypeDDL"></div>
                                <div id="divType">
                                    <select name="typeDDL" id="typeDDL1" class="form-control" required>
                                        <option value="" disabled="disabled" selected="selected">Select Type</option>
                                        <?php
                                        $Result=$_AssetBao->getAllAssetType();
                                        if ($Result->getIsSuccess()){
                                            $TypeList=$Result->getResultObject();
                                            foreach ($TypeList as $type){
                                                ?>
                                                <option value="<?php echo $type->getAssetTypeId(); ?>" <?php
                                                if (isset($_GET['edit'])){
                                                    if ($type->getAssetTypeId()==$getRow->getAssetTypeId()){
                                                        echo 'selected="selected"';
                                                    }
                                                }
                                                ?>><?php echo $type->getAssetTypeName(); ?></option>
                                        <?php
                                            }
                                        }
                                        ?>
                                    </select>
                                </div>
                            </div>
                        </div>

                        <!--Serial No-->
                        <div class="form-group">
                            <label for="serialNo" class="control-label col-md-3">Serial No :</label>
                            <div class=" col-md-7">
                                <input type="text" name="serialNo" id="serialNo" class="form-control" onblur="checkSerialJS();" value="<?php
                                if (isset($_GET['edit'])){
                                    echo $getRow->getAssetSerialNo();
                                }
                                ?>" required>
                                <span id="spnSerialNo" class="text-danger"></span>
                            </div>
                        </div>

                        <!--Model No-->
                        <div class="form-group">
                            <label for="modelNo" class="control-label col-md-3">Model No :</label>
                            <div class=" col-md-7">
                                <input type="text" name="modelNo" id="modelNo" class="form-control" value="<?php
                                if (isset($_GET['edit'])){
                                    echo $getRow->getAssetModelNo();
                                }
                                ?>">
                            </div>
                        </div>

                        <!--Brand-->
                        <div class="form-group">
                            <label for="brand" class="control-label col-md-3">Brand :</label>
                            <div class=" col-md-7">
                                <input type="text" name="brand" id="brand" class="form-control" value="<?php
                                if (isset($_GET['edit'])){
                                    echo $getRow->getAssetBrand();
                                }
                                ?>" required>
                            </div>
                        </div>

                        <!--Purchase Date-->
                        <div class="form-group">
                            <label for="purchaseDate" class="control-label col-md-3">Purchase Date :</label>
                            <div class=" col-md-7">
                                <input type="date" name="purchaseDate" id="purchaseDate" class="form-control" value="<?php
                                if (isset($_GET['edit'])){
                                    echo $getRow->getAssetPurchaseDate();
                                }
                                ?>">
                            </div>
                        </div>

                        <!--Current Status-->
                        <div class="form-group">
                            <label for="status" class="control-label col-md-3">Current Status :</label>
                            <div class=" col-md-7">
                                <select name="status" id="status" class="form-control" required>
                                    <option value="" selected="selected" disabled="disabled">Select Status</option>
                                    <option value="Working" class="text-success" <?php
                                    if (isset($_GET['edit'])){
                                        if ($getRow->getAssetStatus()=="Working"){
                                            echo 'selected="selected"';
                                        }
                                    }
                                    ?>>Working</option>
                                    <option value="On Repair" class="text-warning"<?php
                                    if (isset($_GET['edit'])){
                                        if ($getRow->getAssetStatus()=="On Repair"){
                                            echo 'selected="selected"';
                                        }
                                    }
                                    ?>>On Repair</option>
                                    <option value="Damaged" class="text-danger"<?php
                                    if (isset($_GET['edit'])){
                                        if ($getRow->getAssetStatus()=="Damaged"){
                                            echo 'selected="selected"';
                                        }
                                    }
                                    ?>>Damaged</option>
                                </select>
                            </div>
                        </div>

                        <!--Configuration-->
                        <div class="form-group">
                            <label for="configuration" class="control-label col-md-3">Configuration :</label>
                            <div class=" col-md-7">
                                <textarea name="configuration" id="configuration" rows="5" class="form-control" required><?php
                                    if (isset($_GET['edit'])){
                                        echo $getRow->getAssetConfiguration();
                                    }
                                    ?></textarea>
                            </div>
                        </div>

                        <!--Purchased From-->
                        <div class="form-group">
                            <label for="purchasedFrom" class="control-label col-md-3">Purchased From :</label>
                            <div class=" col-md-7">
                                <input type="text" name="purchasedFrom" id="purchasedFrom" class="form-control" value="<?php
                                if (isset($_GET['edit'])){
                                    echo $getRow->getAssetPurchasedFrom();
                                }
                                ?>" required>
                            </div>
                        </div>

                        <!--Cost-->
                        <div class="form-group">
                            <label for="cost" class="control-label col-md-3">Price :</label>
                            <div class=" col-md-7">
                                <input type="number" min="0" name="cost" id="cost" class="form-control" value="<?php
                                if (isset($_GET['edit'])){
                                    echo $getRow->getAssetCost();
                                }
                                ?>" required>
                            </div>
                        </div>

                        <!--Warranty Limit-->
                        <div class="form-group">
                            <label for="warranty" class="control-label col-md-3">Warranty Limit :</label>
                            <div class=" col-md-7">
                                <input type="date" name="warranty" id="warranty" class="form-control" value="<?php
                                if (isset($_GET['edit'])){
                                    echo $getRow->getAssetWarrantyLimit();
                                }
                                ?>" required>
                            </div>
                        </div>

                        <!--Button-->
                        <div class="form-group">
                            <?php
                            if (!isset($_GET['edit'])){
                                ?>
                                <input type="submit" class="btn btn-primary col-md-2 col-md-offset-5" name="addAsset" value="Add" id="addAsset">
                                <?php
                            }else{
                                ?>
                                <input type="submit" class="btn btn-primary col-md-2 col-md-offset-5" name="update" value="Update" id="update">
                                <?php
                            }
                            ?>
                        </div>
                    </form>
                </div>
            </div>
        </div>
        <div class="col-md-12">
            <hr>
        </div>
        <div class="col-md-12">
            <div class="panel panel-table">
                <table class="table table-bordered table-responsive">
                    <!--Header Row-->
                    <tr>
                        <th>Type</th>
                        <th>Serial No</th>
                        <th>Model No</th>
                        <th>Brand</th>
                        <th>Purchase Date</th>
                        <th>Current Status</th>
                        <th>Configuration</th>
                        <th>Received By</th>
                        <th>Purchased From</th>
                        <th>Price</th>
                        <th>Warranty Limit</th>
                        <th>Edit</th>
                        <th>Delete</th>
                    </tr>

                    <!--Table Cells-->
                    <?php
                    $Result=$_AssetBao->getAllAsset();
                    if($Result->getIsSuccess()) {
                        $AssetList = $Result->getResultObject();

                        foreach ($AssetList as $asset) {
                            ?>
                            <tr <?php if ($asset->getAssetStatus()=="Working"){
                                echo 'class="table-cell alert-success"';
                            }elseif ($asset->getAssetStatus()=="On Repair"){
                                echo 'class="table-cell alert-warning"';
                            }else{
                                echo 'class="table-cell alert-danger"';
                            }
                                ?>>
                                <td><?php echo $_AssetBao->getTypeById($asset->getAssetTypeId())->getResultObject()->getAssetTypeName(); ?></td>
                                <td><a href="asset_details.php?serialNo=<?php echo $asset->getAssetSerialNo(); ?>" class="table-a"><?php echo $asset->getAssetSerialNo(); ?></a></td>
                                <td><?php echo $asset->getAssetModelNo(); ?></td>
                                <td><?php echo $asset->getAssetBrand(); ?></td>
                                <td><?php echo $asset->getAssetPurchaseDate(); ?></td>
                                <td><?php echo $asset->getAssetStatus(); ?></td>
                                <td><?php if (strlen($asset->getAssetConfiguration())>50){
                                    echo substr($asset->getAssetConfiguration(),0,50).'...';
                                    }else{
                                    echo $asset->getAssetConfiguration();
                                    } ?>
                                </td>
                                <?php
                                $StuffName=$_AssetBao->getStuffById($asset->getAssetStuffId())->getResultObject();
                                ?>
                                <td><a href="user_details.php?id=<?php echo $StuffName->getID(); ?>" class="table-a"><?php
                                echo $StuffName->getFirstName().' '.$StuffName->getLastName();
                                ?></a></td>

                                <td><?php echo $asset->getAssetPurchasedFrom(); ?></td>

                                <td><?php echo $asset->getAssetCost(); ?></td>

                                <td><?php echo $asset->getAssetWarrantyLimit(); ?></td>

                                <td><a href="?edit=<?php echo $asset->getAssetId(); ?>"
                                                          onclick="return confirm('sure to edit !!');">edit</a></td>

                                <td><a href="?del=<?php echo $asset->getAssetId(); ?>"
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
    </div>

    <!--Asset Type
    <div id="AssetType" class="tabcontent myPanel col-md-12">
        <br>
        <div class="col-md-8 col-md-offset-2">
            <div class="panel myPanel">
                <div class="panel-heading myHeading">
                    <strong>&nbsp;Add Asset Type</strong>
                </div>
                <div class="panel-body">
                    <div class="form-horizontal"-->

                        <!--Type-
                        <div class="form-group">
                            <label for="assetType" class="col-md-3 control-label">Type :</label>
                            <div class="col-md-6">
                                <input id="assetType" type="text" class="form-control" name="assetType" required>
                            </div>
                        </div-->

                        <!--div class="form-group">
                            <div class="col-md-6 col-md-offset-5">
                                <button type="button" id="btnAssetType" class="btn btn-primary col-md-3" onclick="typeJS();">Add</button>
                                <span id="type-success" hidden class="text-success">&nbsp;&nbsp;&nbsp;&nbsp;Successfully created</span>
                                <span id="type-exists" hidden class="text-danger">&nbsp;&nbsp;&nbsp;&nbsp;Type already exists</span>
                                <span id="type-danger" hidden class="text-danger">&nbsp;&nbsp;&nbsp;&nbsp;Type is required</span>
                            </div>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </div>
</div-->
<script>
    //Tab Selection
    function openTab(evt, cityName) {
        var i, tabcontent, tablinks;
        tabcontent = document.getElementsByClassName("tabcontent");
        for (i = 0; i < tabcontent.length; i++) {
            tabcontent[i].style.display = "none";
        }
        tablinks = document.getElementsByClassName("tablinks");
        for (i = 0; i < tablinks.length; i++) {
            tablinks[i].className = tablinks[i].className.replace(" active", "");
        }
        document.getElementById(cityName).style.display = "block";
        evt.currentTarget.className += " active";
    } 

    //Select Default Tab on refresh
    document.getElementById("defaultOpen").click();

    //Create Type
    function typeJS() {
        var type=$('#assetType').val();
        if(type!=""){
            $.ajax({
                url:'./modules/assetArchive/ui/addType.inc',
                type:"get",
                data:{val:type},
                success:function (data) {
                    $('#type-success').fadeIn().delay(500).fadeOut();
                    $('#assetType').val(null);
                    $('#divType').css('display','none');
                    $('#typeDDL1').prop('required',false);
                    $('#divTypeDDL').html(data);
                    alert('Asset Type Added');
                },
                error:function (data) {
                    alert('Error!!');
                }
            });
        }else{
            $('#type-danger').fadeIn().delay(500).fadeOut();
        }
    }

    function checkSerialJS() {
        var serial=$('#serialNo').val();
        $.ajax({
            url:"./modules/assetArchive/ui/checkSerial.inc",
            type:"get",
            data:{val:serial},
            success:function (data) {
                $('#spnSerialNo').text(data);
                if(data==""){
                    $('#addAsset').prop('disabled',false);
                    $('#update').prop('disabled',false);
                }else{
                    $('#addAsset').prop('disabled',true);
                    $('#update').prop('disabled',true);
                }
            },
            error:function (data) {

            }
        });
    }
</script>