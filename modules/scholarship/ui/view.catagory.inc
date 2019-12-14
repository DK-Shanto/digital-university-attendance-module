<?php

include_once 'blade/view.catagory.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">Catagory Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
				<div class="form-group">
              	<label class="control-label col-sm-2" for="txtName">Category Name:</label>
              	<div class="col-sm-10">
					<input type="text" name="txtName" placeholder="Catagory Name" value="<?php 
					if(isset($_GET['edit'])) echo $globalCatagory->getCatagoryName();  ?>" />
				</div>				
				</div>
				<div>
				<label class="control-label col-sm-2" for="txtShortCode">Short Name:</label>
				<div class="col-sm-10">
					<input type="text" name="txtShortCode" placeholder="Short code name" value="<?php 
					if(isset($_GET['edit'])) echo $globalCatagory->getShortName();  ?>" />
				</div>
				</div>
		        <div class="form-group">        
	              <div class="col-sm-offset-2 col-sm-10">
						<?php
						if(isset($_GET['edit']))
						{
							?>
							<button type="submit" name="update">update</button>
							<?php
						}
						else
						{
							?>
							<button type="submit" name="save">save</button>
							<?php
						}
						?>
					</div>
				</div>	

		</form>

	</div>
	</div>

	<div class="panel-body">

	<table class="table table-bordered">
	<?php
	
	
	$Result = $_CatagoryBAO->getAllCatagorys();

	//if DAO access is successful to load all the Catagorys then show them one by one
	if($Result->getIsSuccess()){

		$CatagoryList = $Result->getResultObject();
	?>
		<tr>
			<th>Category Name</th>
			<th>Short Name</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($CatagoryList); $i++) {
			$Catagory = $CatagoryList[$i];
			?>
		    <tr>
			    <td><?php echo $Catagory->getCatagoryName(); ?></td>
			    <td><?php echo $Catagory->getShortName(); ?></td>
			    <td><a href="?edit=<?php echo $Catagory->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $Catagory->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
		    </tr>
	    <?php

		}

	}
	else{

		echo $Result->getResultObject(); //giving failure message
	}

	?>
	</table>
	</div>
</div>
