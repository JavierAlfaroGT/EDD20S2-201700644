const app = require('./app');
app.listen(4000, ()=> console.log('JAVIER the server is on port 4000'));

async function main(){
    await app.listen(4000);
    console.log('Server is running');
}


