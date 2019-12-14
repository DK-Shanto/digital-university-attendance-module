<?php

include_once 'blade/view.cocurricular.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">Cocurricular Activity Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
				<div class="form-group">
              	<label class="control-label col-sm-4" for="txtName">Cocurricular Activity Name:</label>
              	<div class="col-sm-8">
					<input type="text" name="txtName" placeholder="Cocurricular Name" value="<?php 
					if(isset($_GET['edit'])) echo $globalCocurricular->getCocurricularName();  ?>" />
				</div>				
				</div>
				<div>
				<label class="control-label col-sm-4" for="txtShortCode">Short Name:</label>
				<div class="col-sm-8">
					<input type="text" name="txtShortCode" placeholder="Short code name" value="<?php 
					if(isset($_GET['edit'])) echo $globalCocurricular->getShortName();  ?>" />
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
	
	
	$Result = $_CocurricularBAO->getAllCocurriculars();

	//if DAO access is successful to load all the Cocurriculars then show them one by one
	if($Result->getIsSuccess()){

		$CocurricularList = $Result->getResultObject();
	?>
		<tr>
			<th>Cocurricular Name</th>
			<th>Short Name</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($CocurricularList); $i++) {
			$Cocurricular = $CocurricularList[$i];
			?>
		    <tr>
			    <td><?php echo $Cocurricular->getCocurricularName(); ?></td>
			    <td><?php echo $Cocurricular->getShortName(); ?></td>
			    <td><a href="?edit=<?php echo $Cocurricular->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $Cocurricular->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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
