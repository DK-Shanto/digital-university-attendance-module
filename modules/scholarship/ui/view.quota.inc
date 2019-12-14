<?php

include_once 'blade/view.quota.blade.inc';
include_once COMMON.'class.common.inc';

?>

<div class="panel panel-default">
    
    <div class="panel-heading">Quota Information</div>
    
    <div class="panel-body">

	<div id="form">
		<form method="post" class="form-horizontal">
				<div class="form-group">
              	<label class="control-label col-sm-2" for="txtName">Quota Name:</label>
              	<div class="col-sm-10">
					<input type="text" name="txtName" placeholder="Quota Name" value="<?php 
					if(isset($_GET['edit'])) echo $globalQuota->getQuotaName();  ?>" />
				</div>				
				</div>
				<div>
				<label class="control-label col-sm-2" for="txtShortCode">Short Name:</label>
				<div class="col-sm-10">
					<input type="text" name="txtShortCode" placeholder="Short code name" value="<?php 
					if(isset($_GET['edit'])) echo $globalQuota->getShortName();  ?>" />
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
	
	
	$Result = $_QuotaBAO->getAllQuotas();

	//if DAO access is successful to load all the Quotas then show them one by one
	if($Result->getIsSuccess()){

		$QuotaList = $Result->getResultObject();
	?>
		<tr>
			<th>Quota Name</th>
			<th>Short Name</th>
		</tr>
		<?php
		for($i = 0; $i < sizeof($QuotaList); $i++) {
			$Quota = $QuotaList[$i];
			?>
		    <tr>
			    <td><?php echo $Quota->getQuotaName(); ?></td>
			    <td><?php echo $Quota->getShortName(); ?></td>
			    <td><a href="?edit=<?php echo $Quota->getID(); ?>" onclick="return confirm('sure to edit !'); " >edit</a></td>
			    <td><a href="?del=<?php echo $Quota->getID(); ?>" onclick="return confirm('sure to delete !'); " >delete</a></td>
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
