
<?php

include_once 'blade/view.ccamenu.blade.inc';
include_once COMMON.'class.common.inc';
//include_once './common/class.common.cca.inc';

?>
<div class="panel panel-default">
        <div class="panel panel-default">
                <div class="panel-heading">Manage Catagory</div>
            	<div class="panel-body">

			<div id="form">
				<form action="#" method="post" class="form-horizontal">


					<div class="form-group">
						<label class="control-label col-sm-4" for="Catagory"> Add Catagory: </label>
						<div class="col-sm-6">
						<input type="text" class="form-control"  name="Catagory" placeholder="Add Catagory Name......" value="<?php
					if(isset($_GET['edit'])) echo $globalUser->getCatagory();  ?>"/>
						</div>
					</div>

					<div>
    					<?php
						if(isset($_GET['edit']))
						{
							?>
							<button style=" margin-left: 80px; width: 150px" type="submit" value="update" name="update">update</button>
							<?php
						}
						else
						{
							?>
							<button style=" margin-left: 80px; width: 150px" type="submit" value="save" name="addcat">save </button>
							<?php
						}
						?>

				<br>
        <br>




			</div>
		</div>
    	</form>
    <div class="panel-body">

	<table class="table table-bordered">
	<?php


	$Result = $_CCAMENUBAO->getCATA();

	//if DAO access is successful to load all the users then show them one by one
	if($Result->getIsSuccess()){

		$CCAList = $Result->getResultObject();
	?>
		<tr>

			<th>Category</th>

		</tr>
		<?php
		for($i = 0; $i < sizeof($CCAList); $i++) {
			$CCA = $CCAList[$i];
			?>
		    <tr>


			  <td><?php echo $CCA->getCatagory(); ?></td>
			    <td>
			    <a href="?edit=<?php echo $CCA->getcatID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a>
			    </td>

			    <td>
			    <a href="?del=<?php echo $CCA->getcatID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a>
			    </td>
		    </tr>
	    <?php

		}

	}
	else{

		echo $Result->getResultObject();
	}

	?>
	</table>
