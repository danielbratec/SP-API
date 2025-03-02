const axios = require('axios');

async function getAccessToken(clientId, clientSecret, refreshToken, region) {
  const tokenUrl = `https://api.amazon.${region}/auth/o2/token`;

  const params = new URLSearchParams();
  params.append('grant_type', 'refresh_token');
  params.append('refresh_token', refreshToken);
  params.append('client_id', clientId);
  params.append('client_secret', clientSecret);

  try {
    const response = await axios.post(tokenUrl, params, {
      headers: { 'Content-Type': 'application/x-www-form-urlencoded' },
    });
    return response.data.access_token;
  } catch (error) {
    console.error('Erro ao obter o Access Token:', error.response ? error.response.data : error.message);
    throw error;
  }
}

//Exemplo de uso
async function main(){
    const clientId = 'YOUR_CLIENT_ID';
    const clientSecret = 'YOUR_CLIENT_SECRET';
    const refreshToken = 'YOUR_REFRESH_TOKEN';
    const region = 'com.br'; // or com, .de, .uk, etc.

    try{
        const accessToken = await getAccessToken(clientId,clientSecret,refreshToken,region);
        console.log("Access Token:", accessToken);
        //execute other SP-API calls with the accessToken.
    } catch (error){
        console.log("Error during main execution", error);
    }
}

main();